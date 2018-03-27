// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "pch.h"

using namespace xbox::httpclient;
using namespace xbox::httpclient::log;

HCAPI 
HCSettingsSetLogLevel(
    _In_ HC_LOG_LEVEL traceLevel
    ) HC_NOEXCEPT
try
{
    HCTraceLevel internalTraceLevel = HC_TRACELEVEL_OFF;
    switch (traceLevel)
    {
        case LOG_OFF: internalTraceLevel = HC_TRACELEVEL_OFF; break;
        case LOG_ERROR: internalTraceLevel = HC_TRACELEVEL_ERROR; break;
        case LOG_IMPORTANT: internalTraceLevel = HC_TRACELEVEL_IMPORTANT; break;
        case LOG_WARNING: internalTraceLevel = HC_TRACELEVEL_WARNING; break;
        case LOG_INFORMATION: internalTraceLevel = HC_TRACELEVEL_INFORMATION; break;
        case LOG_VERBOSE: internalTraceLevel = HC_TRACELEVEL_VERBOSE; break;
        default: return E_INVALIDARG;
    };

    HC_TRACE_SET_VERBOSITY(HTTPCLIENT, internalTraceLevel);
    HC_TRACE_INFORMATION(HTTPCLIENT, "HCSettingsSetLogLevel: %d", traceLevel);
    return S_OK;
}
CATCH_RETURN()

HCAPI 
HCSettingsGetLogLevel(
    _Out_ HC_LOG_LEVEL* traceLevel
    ) HC_NOEXCEPT
try
{
    if (traceLevel == nullptr)
    {
        return E_INVALIDARG;
    }

    *traceLevel = static_cast<HC_LOG_LEVEL>(HC_TRACE_GET_VERBOSITY(HTTPCLIENT)); 
    return S_OK;
}
CATCH_RETURN()
