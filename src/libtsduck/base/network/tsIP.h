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
//!  @ingroup net
//!  Include the multiple and messy system headers for IP networking.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsPlatform.h"

#if defined(TS_WINDOWS)
    #include "tsBeforeStandardHeaders.h"
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <mswsock.h>
    #include "tsAfterStandardHeaders.h"
    #if defined(TS_MSC)
        #pragma comment(lib, "ws2_32.lib")
    #endif
#else
    #include "tsBeforeStandardHeaders.h"
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <net/if.h>
    #include <netinet/in.h>
    #include <netinet/tcp.h>
    #include <netdb.h>
    #if defined(TS_MAC)
        #include <ifaddrs.h>
    #endif
    #include "tsAfterStandardHeaders.h"
#endif
