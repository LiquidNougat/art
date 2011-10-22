/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*
 * Handle requests.
 */
#ifndef ART_JDWP_JDWPHANDLER_H_
#define ART_JDWP_JDWPHANDLER_H_

#include "jdwp_expand_buf.h"

namespace art {

namespace JDWP {

/*
 * JDWP message header for a request.
 */
struct JdwpReqHeader {
  uint32_t length;
  uint32_t id;
  uint8_t cmdSet;
  uint8_t cmd;
};

/*
 * Process a request from the debugger.
 *
 * "buf" points past the header, to the content of the message.  "dataLen"
 * can therefore be zero.
 */
void ProcessRequest(JdwpState* state, const JdwpReqHeader* pHeader,
    const uint8_t* buf, int dataLen, ExpandBuf* pReply);

/* helper function */
void AddLocation(ExpandBuf* pReply, const JdwpLocation* pLoc);

}  // namespace JDWP

}  // namespace art

#endif  // ART_JDWP_JDWPHANDLER_H_
