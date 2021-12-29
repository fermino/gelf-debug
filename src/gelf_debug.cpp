#include "gelf_debug.h"

UDPTransport GELF_DEBUG_TRANSPORT = UDPTransport(GELF_DEBUG_HOST, GELF_DEBUG_PORT);

// This objects will be extern, so we can assign properties from outside this file
Publisher GELF_DEBUG_PUBLISHER = Publisher(&GELF_DEBUG_TRANSPORT);
Message GELF_DEBUG_MESSAGE = Message("");
