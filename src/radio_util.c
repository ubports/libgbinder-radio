/*
 * Copyright (C) 2018-2020 Jolla Ltd.
 * Copyright (C) 2018-2020 Slava Monich <slava.monich@jolla.com>
 *
 * You may use this file under the terms of the BSD license as follows:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *   3. Neither the names of the copyright holders nor the names of its
 *      contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation
 * are those of the authors and should not be interpreted as representing
 * any official policies, either expressed or implied.
 */

#include "radio_util.h"
#include "radio_log.h"

GLOG_MODULE_DEFINE("gbinder-radio");

const char*
radio_req_name(
    RADIO_REQ req)
{
    switch (req) {
    case RADIO_REQ_SET_RESPONSE_FUNCTIONS:   return "setResponseFunctions";
    case RADIO_REQ_RESPONSE_ACKNOWLEDGEMENT: return "responseAcknowledgement";
#define RADIO_REQ_(req,resp,Name,NAME) \
    case RADIO_REQ_##NAME: return #Name;
    RADIO_CALL_1_0(RADIO_REQ_)
    RADIO_CALL_1_1(RADIO_REQ_)
#undef RADIO_REQ_
    case RADIO_REQ_START_NETWORK_SCAN_1_2:                 return "startNetworkScan_1_2";
    case RADIO_REQ_SET_INDICATION_FILTER_1_2:              return "setIndicationFilter_1_2";
    case RADIO_REQ_SET_SIGNAL_STRENGTH_REPORTING_CRITERIA: return "setSignalStrengthReportingCriteria";
    case RADIO_REQ_SET_LINK_CAPACITY_REPORTING_CRITERIA:   return "setLinkCapacityReportingCriteria";
    case RADIO_REQ_SETUP_DATA_CALL_1_2:                    return "setupDataCall_1_2";
    case RADIO_REQ_DEACTIVATE_DATA_CALL_1_2:               return "deactivateDataCall_1_2";
    case RADIO_REQ_ANY:
        break;
    }
    return NULL;
}

const char*
radio_resp_name(
    RADIO_RESP resp)
{
    switch (resp) {
    case RADIO_RESP_ACKNOWLEDGE_REQUEST: return "acknowledgeRequest";
#define RADIO_RESP_(req,resp,Name,NAME) \
    case RADIO_RESP_##NAME: return #Name "Response";
    RADIO_CALL_1_0(RADIO_RESP_)
    RADIO_CALL_1_1(RADIO_RESP_)
#undef RADIO_RESP_
    case RADIO_RESP_GET_CELL_INFO_LIST_1_2: return "getCellInfoListResponse_1_2";
    case RADIO_RESP_GET_ICC_CARD_STATUS_1_2: return "getIccCardStatusResponse_1_2";
    case RADIO_RESP_SET_SIGNAL_STRENGTH_REPORTING_CRITERIA: return "setSignalStrengthReportingCriteriaResponse";
    case RADIO_RESP_SET_LINK_CAPACITY_REPORTING_CRITERIA: return "setLinkCapacityReportingCriteriaResponse";
    case RADIO_RESP_GET_CURRENT_CALLS_1_2: return "getCurrentCallsResponse_1_2";
    case RADIO_RESP_GET_SIGNAL_STRENGTH_1_2: return "getSignalStrengthResponse_1_2";
    case RADIO_RESP_GET_VOICE_REGISTRATION_STATE_1_2: return "getVoiceRegistrationStateResponse_1_2";
    case RADIO_RESP_GET_DATA_REGISTRATION_STATE_1_2: return "getDataRegistrationStateResponse_1_2";
    case RADIO_RESP_ANY:
        break;
    }
    return NULL;
}

const char*
radio_ind_name(
    RADIO_IND ind)
{
    switch (ind) {
#define RADIO_IND_(code,Name,NAME) \
    case RADIO_IND_##NAME: return #Name;
    RADIO_EVENT_1_0(RADIO_IND_)
    RADIO_EVENT_1_1(RADIO_IND_)
    RADIO_EVENT_1_2(RADIO_IND_)
#undef RADIO_IND_
    case RADIO_IND_ANY:
        break;
    }
    return NULL;
}

RADIO_RESP
radio_req_resp(
    RADIO_REQ req)
{
    switch (req) {
#define RADIO_REQ_(req,resp,Name,NAME) \
    case RADIO_REQ_##NAME: return RADIO_RESP_##NAME;
    RADIO_CALL_1_0(RADIO_REQ_)
    RADIO_CALL_1_1(RADIO_REQ_)
#undef RADIO_REQ_
    case RADIO_REQ_SET_RESPONSE_FUNCTIONS:
    case RADIO_REQ_RESPONSE_ACKNOWLEDGEMENT:
    case RADIO_REQ_START_NETWORK_SCAN_1_2:
    case RADIO_REQ_SET_INDICATION_FILTER_1_2:
    case RADIO_REQ_SET_SIGNAL_STRENGTH_REPORTING_CRITERIA:
    case RADIO_REQ_SET_LINK_CAPACITY_REPORTING_CRITERIA:
    case RADIO_REQ_SETUP_DATA_CALL_1_2:
    case RADIO_REQ_DEACTIVATE_DATA_CALL_1_2:
    case RADIO_REQ_ANY:
        break;
    }
    return RADIO_RESP_NONE;
}

/*
 * Local Variables:
 * mode: C
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 */

