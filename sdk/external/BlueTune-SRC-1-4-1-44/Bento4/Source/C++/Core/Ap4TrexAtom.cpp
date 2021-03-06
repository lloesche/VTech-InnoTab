/*****************************************************************
|
|    AP4 - trex Atoms 
|
|    Copyright 2002-2008 Axiomatic Systems, LLC
|
|
|    This file is part of Bento4/AP4 (MP4 Atom Processing Library).
|
|    Unless you have obtained Bento4 under a difference license,
|    this version of Bento4 is Bento4|GPL.
|    Bento4|GPL is free software; you can redistribute it and/or modify
|    it under the terms of the GNU General Public License as published by
|    the Free Software Foundation; either version 2, or (at your option)
|    any later version.
|
|    Bento4|GPL is distributed in the hope that it will be useful,
|    but WITHOUT ANY WARRANTY; without even the implied warranty of
|    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
|    GNU General Public License for more details.
|
|    You should have received a copy of the GNU General Public License
|    along with Bento4|GPL; see the file COPYING.  If not, write to the
|    Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA
|    02111-1307, USA.
|
 ****************************************************************/

/*----------------------------------------------------------------------
|   includes
+---------------------------------------------------------------------*/
#include "Ap4TrexAtom.h"
#include "Ap4AtomFactory.h"
#include "Ap4Utils.h"

/*----------------------------------------------------------------------
|   dynamic cast support
+---------------------------------------------------------------------*/
AP4_DEFINE_DYNAMIC_CAST_ANCHOR(AP4_TrexAtom)

/*----------------------------------------------------------------------
|   AP4_TrexAtom::Create
+---------------------------------------------------------------------*/
AP4_TrexAtom*
AP4_TrexAtom::Create(AP4_Size size, AP4_ByteStream& stream)
{
    AP4_UI32 version;
    AP4_UI32 flags;
    if (AP4_FAILED(AP4_Atom::ReadFullHeader(stream, version, flags))) return NULL;
    if (version != 0) return NULL;
    return new AP4_TrexAtom(size, version, flags, stream);
}

/*----------------------------------------------------------------------
|   AP4_TrexAtom::AP4_TrexAtom
+---------------------------------------------------------------------*/
AP4_TrexAtom::AP4_TrexAtom(AP4_UI32 track_id,
                           AP4_UI32 default_sample_description_index,
                           AP4_UI32 default_sample_duration,
                           AP4_UI32 default_sample_size,
                           AP4_UI32 default_sample_flags) :
    AP4_Atom(AP4_ATOM_TYPE_TREX, AP4_FULL_ATOM_HEADER_SIZE+20, 0, 0),
    m_TrackId(track_id),
    m_DefaultSampleDescriptionIndex(default_sample_description_index),
    m_DefaultSampleDuration(default_sample_duration),
    m_DefaultSampleSize(default_sample_size),
    m_DefaultSampleFlags(default_sample_flags)
{
}

/*----------------------------------------------------------------------
|   AP4_TrexAtom::AP4_TrexAtom
+---------------------------------------------------------------------*/
AP4_TrexAtom::AP4_TrexAtom(AP4_UI32        size, 
                           AP4_UI32        version,
                           AP4_UI32        flags,
                           AP4_ByteStream& stream) :
    AP4_Atom(AP4_ATOM_TYPE_TREX, size, version, flags)
{
    stream.ReadUI32(m_TrackId);
    stream.ReadUI32(m_DefaultSampleDescriptionIndex);
    stream.ReadUI32(m_DefaultSampleDuration);
    stream.ReadUI32(m_DefaultSampleSize);
    stream.ReadUI32(m_DefaultSampleFlags);
}

/*----------------------------------------------------------------------
|   AP4_TrexAtom::WriteFields
+---------------------------------------------------------------------*/
AP4_Result
AP4_TrexAtom::WriteFields(AP4_ByteStream& stream)
{
    stream.WriteUI32(m_TrackId);
    stream.WriteUI32(m_DefaultSampleDescriptionIndex);
    stream.WriteUI32(m_DefaultSampleDuration);
    stream.WriteUI32(m_DefaultSampleSize);
    stream.WriteUI32(m_DefaultSampleFlags);

    return AP4_SUCCESS;
}

/*----------------------------------------------------------------------
|   AP4_TrexAtom::InspectFields
+---------------------------------------------------------------------*/
AP4_Result
AP4_TrexAtom::InspectFields(AP4_AtomInspector& inspector)
{
    inspector.AddField("track id", m_TrackId);
    inspector.AddField("default sample description index", m_DefaultSampleDescriptionIndex);
    inspector.AddField("default sample duration", m_DefaultSampleDuration);
    inspector.AddField("default sample size", m_DefaultSampleSize);
    inspector.AddField("default sample flags", m_DefaultSampleFlags, AP4_AtomInspector::HINT_HEX);

    return AP4_SUCCESS;
}
