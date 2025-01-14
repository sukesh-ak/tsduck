//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2022, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  Representation of a subtitling_descriptor
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsAbstractDescriptor.h"
#include "tsVariable.h"

namespace ts {
    //!
    //! Representation of a subtitling_descriptor.
    //! @see ETSI EN 300 468, 6.2.41.
    //! @ingroup descriptor
    //!
    class TSDUCKDLL SubtitlingDescriptor : public AbstractDescriptor
    {
    public:
        //!
        //! An item entry.
        //!
        struct TSDUCKDLL Entry
        {
            // Public members
            UString  language_code;         //!< ISO-639 language code, 3 characters.
            uint8_t  subtitling_type;       //!< Subtitling type.
            uint16_t composition_page_id;   //!< Composition page identifier.
            uint16_t ancillary_page_id;     //!< Ancillary page identifier.

            //!
            //! Default constructor.
            //! @param [in] code ISO-639 language code, 3 characters. Can be null.
            //! @param [in] subt Subtitling type.
            //! @param [in] comp Composition page identifier.
            //! @param [in] ancil Ancillary page identifier.
            //!
            Entry(const UChar* code = nullptr, uint8_t subt = 0, uint16_t comp = 0, uint16_t ancil = 0);

            //!
            //! Default constructor.
            //! @param [in] code ISO-639 language code, 3 characters.
            //! @param [in] subt Subtitling type.
            //! @param [in] comp Composition page identifier.
            //! @param [in] ancil Ancillary page identifier.
            //!
            Entry(const UString& code, uint8_t subt = 0, uint16_t comp = 0, uint16_t ancil = 0);
        };

        //!
        //! List of language entries.
        //!
        typedef std::list<Entry> EntryList;

        //!
        //! Maximum number of language entries to fit in 255 bytes.
        //!
        static const size_t MAX_ENTRIES = 31;

        // Public members
        EntryList entries;  //!< The list of item entries in the descriptor.

        //!
        //! Default constructor.
        //!
        SubtitlingDescriptor();

        //!
        //! Constructor from a binary descriptor
        //! @param [in,out] duck TSDuck execution context.
        //! @param [in] bin A binary descriptor to deserialize.
        //!
        SubtitlingDescriptor(DuckContext& duck, const Descriptor& bin);

        // Inherited methods
        DeclareDisplayDescriptor();

    protected:
        // Inherited methods
        virtual void clearContent() override;
        virtual void serializePayload(PSIBuffer&) const override;
        virtual void deserializePayload(PSIBuffer&) override;
        virtual void buildXML(DuckContext&, xml::Element*) const override;
        virtual bool analyzeXML(DuckContext&, const xml::Element*) override;
    };
}
