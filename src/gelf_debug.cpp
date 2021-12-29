#include "gelf_debug.h"

// This objects will be extern, so we can assign properties from outside this file
UDPTransport GELF_DEBUG_TRANSPORT = UDPTransport(nullptr, GELF_DEBUG_PORT);
Publisher GELF_DEBUG_PUBLISHER = Publisher(&GELF_DEBUG_TRANSPORT);
Message GELF_DEBUG_MESSAGE = Message("");
