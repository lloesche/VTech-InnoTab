/* 

TestFramerate

Test/Sample program for framerate manager 

Copyright (C) A. Schiffler, August 2001

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "SDL.h"

#ifdef WIN32
#include <windows.h>
#include "SDL_framerate.h"
#include "SDL_gfxPrimitives.h"
#else
#include "SDL/SDL_framerate.h"
#include "SDL/SDL_gfxPrimitives.h"
#endif

#define WIDTH	480 /*lcd_auo_A043FL01's size*/
#define HEIGHT	272

void HandleEvent()
{
	SDL_Event event; 

	/* Check for events */
	while ( SDL_PollEvent(&event) ) {
		fprintf(stderr, "event.type = %d\n",event.type);
		switch (event.type) {
			 case SDL_KEYDOWN:
			 case SDL_QUIT:
				 exit(0);
				 break;
		}
	}
}

void ClearScreen(SDL_Surface *screen)
{
	int i;
	/* Set the screen to black */
	if ( SDL_LockSurface(screen) == 0 ) {
		Uint32 black;
		Uint8 *pixels;
		black = SDL_MapRGB(screen->format, 0, 0, 0);
		pixels = (Uint8 *)screen->pixels;
		for ( i=0; i<screen->h; ++i ) {
			memset(pixels, black,
				screen->w*screen->format->BytesPerPixel);
			pixels += screen->pitch;
		}
		SDL_UnlockSurface(screen);
	}
}

void Draw(SDL_Surface *screen)
{
	int i,rate,x,y,dx,dy,r,g,b;
	FPSmanager fpsm;
	char message[64];

	/* Initialize variables */
	srand((int)time(NULL));
	i=0;
	x=screen->w/2;
	y=screen->h/2;
	dx=7;
	dy=5;
	r=g=b=255;

	SDL_initFramerate(&fpsm);
	rate = SDL_getFramerate(&fpsm);
	sprintf(message, "Framerate set to %i Hz ...",rate);

	while (1) {
		printf(stderr, "[%s %d]\n",__FILE__,__LINE__);

		/* Set/switch framerate */
		i -= 1;
		if (i<0) {
			/* Set new rate */
			rate=5+5*(rand() % 10);
			SDL_setFramerate(&fpsm,rate);
			sprintf(message, "Framerate set to %i Hz ...",rate);

			/* New timeout */
			i=2*rate;
			/* New Color */
			r=rand() & 255;
			g=rand() & 255;
			b=rand() & 255;
		}

		/* Black screen */
		ClearScreen(screen);

		stringRGBA (screen, WIDTH/2-4*strlen(message),HEIGHT-12,message,255,255,255,255);

		/* Move */
		x += dx;
		y += dy;

		/* Reflect */
		if ((x<0) || (x>screen->w)) { dx=-dx; }
		if ((y<0) || (y>screen->h)) { dy=-dy; }

		/* Draw */
		filledCircleRGBA (screen,x,y,30,r,g,b,255);
		circleRGBA(screen,x,y,30,255,255,255,255);

		/* Display by flipping screens */
		SDL_Flip(screen);

		/* Check events */
		/*HandleEvent();*/  /*SPMP8050 always has a key pressed, so this process will exit itself*/

		/* Delay to fix rate */                   
		SDL_framerateDelay(&fpsm);  
		printf(stderr, "[%s %d]\n",__FILE__,__LINE__);
	}
}

int main(int argc, char *argv[])
{
	SDL_Surface *screen;
	Uint8  video_bpp;
	Uint32 videoflags;
	char title[64];

	/* Generate title strings */
	sprintf (title, "TestFramerate - v%i.%i.%i", SDL_GFXPRIMITIVES_MAJOR, SDL_GFXPRIMITIVES_MINOR, SDL_GFXPRIMITIVES_MICRO);

	/* Initialize SDL */
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n",SDL_GetError());
		exit(1);
	}
	atexit(SDL_Quit);

	video_bpp = 32;	
	videoflags = SDL_SWSURFACE | SDL_SRCALPHA | SDL_RESIZABLE;

	while ( argc > 1 ) {
		--argc;
		if ( strcmp(argv[argc-1], "-bpp") == 0 ) {
			video_bpp = atoi(argv[argc]);
			--argc;
		} else
			if ( strcmp(argv[argc], "-hw") == 0 ) {
				videoflags |= SDL_HWSURFACE;
			} else
				if ( strcmp(argv[argc], "-warp") == 0 ) {
					videoflags |= SDL_HWPALETTE;
				} else
					if ( strcmp(argv[argc], "-fullscreen") == 0 ) {
						videoflags |= SDL_FULLSCREEN;
					} else {
						fprintf(stderr, 
							"Usage: %s [-bpp N] [-warp] [-hw] [-fullscreen]\n",
							argv[0]);
						exit(1);
					}
	}

	/* Force double buffering */
	videoflags |= SDL_DOUBLEBUF;

	/* Set video mode */
	if ( (screen=SDL_SetVideoMode(WIDTH, HEIGHT, video_bpp, videoflags)) == NULL ) {
		fprintf(stderr, "Couldn't set %ix%i %i bpp video mode: %s\n",WIDTH,HEIGHT,video_bpp,SDL_GetError());
		exit(2);
	}

	/* Use alpha blending */
	SDL_SetAlpha(screen, SDL_SRCALPHA, 100); /*old alpha is 0, the src transparent all color, it should bigger than 0 */

	/* Set title for window */
	SDL_WM_SetCaption(title, title);

	/* Do all the drawing work */
	Draw (screen);

	return(0);
}
