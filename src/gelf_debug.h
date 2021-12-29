#ifndef GELF_DEBUG_H
#define GELF_DEBUG_H

#include <UDPTransport.h>
#include <Publisher.h>
#include <Message.h>

#include "gelf_debug_config.h"

#ifndef GELF_DEBUG_HOST
#error You must define GELF_DEBUG_HOST in gelf_debug_config.h
#endif

#ifndef GELF_DEBUG_PORT
#define GELF_DEBUG_PORT (GRAYLOG_UDP_DEFAULT_PORT)
#endif

// This is what actually happens around the gelf lib
#define GELF_DEBUG_SET(var)                                 \
    (GELF_DEBUG_MESSAGE.set(#var, var))
#define GELF_DEBUG_SEND(message)                            \
    (GELF_DEBUG_MESSAGE.set("short_message", message));     \
    (GELF_DEBUG_PUBLISHER.publish(&GELF_DEBUG_MESSAGE));    \
    (GELF_DEBUG_MESSAGE = Message(""))

// This two variables are accessed globally
extern Publisher GELF_DEBUG_PUBLISHER;
extern Message GELF_DEBUG_MESSAGE;

// Variadic macros
#define GELF_DEBUG_1(message, var1) \
    (GELF_DEBUG_SET(var1)); \
    GELF_DEBUG_SEND(message)
#define GELF_DEBUG_2(message, var1, var2) \
    (GELF_DEBUG_SET(var1)); \
    (GELF_DEBUG_SET(var2)); \
    GELF_DEBUG_SEND(message)
#define GELF_DEBUG_3(message, var1, var2, var3) \
    (GELF_DEBUG_SET(var1)); \
    (GELF_DEBUG_SET(var2)); \
    (GELF_DEBUG_SET(var3)); \
    GELF_DEBUG_SEND(message)
#define GELF_DEBUG_4(message, var1, var2, var3, var4) \
    (GELF_DEBUG_SET(var1)); \
    (GELF_DEBUG_SET(var2)); \
    (GELF_DEBUG_SET(var3)); \
    (GELF_DEBUG_SET(var4)); \
    GELF_DEBUG_SEND(message)
#define GELF_DEBUG_5(message, var1, var2, var3, var4, var5) \
    (GELF_DEBUG_SET(var1)); \
    (GELF_DEBUG_SET(var2)); \
    (GELF_DEBUG_SET(var3)); \
    (GELF_DEBUG_SET(var4)); \
    (GELF_DEBUG_SET(var5)); \
    GELF_DEBUG_SEND(message)
#define GELF_DEBUG_6(message, var1, var2, var3, var4, var5, var6) \
    (GELF_DEBUG_SET(var1)); \
    (GELF_DEBUG_SET(var2)); \
    (GELF_DEBUG_SET(var3)); \
    (GELF_DEBUG_SET(var4)); \
    (GELF_DEBUG_SET(var5)); \
    (GELF_DEBUG_SET(var6)); \
    GELF_DEBUG_SEND(message)
#define GELF_DEBUG_7(message, var1, var2, var3, var4, var5, var6, var7) \
    (GELF_DEBUG_SET(var1)); \
    (GELF_DEBUG_SET(var2)); \
    (GELF_DEBUG_SET(var3)); \
    (GELF_DEBUG_SET(var4)); \
    (GELF_DEBUG_SET(var5)); \
    (GELF_DEBUG_SET(var6)); \
    (GELF_DEBUG_SET(var7)); \
    GELF_DEBUG_SEND(message)
#define GELF_DEBUG_8(message, var1, var2, var3, var4, var5, var6, var7, var8) \
    (GELF_DEBUG_SET(var1)); \
    (GELF_DEBUG_SET(var2)); \
    (GELF_DEBUG_SET(var3)); \
    (GELF_DEBUG_SET(var4)); \
    (GELF_DEBUG_SET(var5)); \
    (GELF_DEBUG_SET(var6)); \
    (GELF_DEBUG_SET(var7)); \
    (GELF_DEBUG_SET(var8)); \
    GELF_DEBUG_SEND(message)

// I don't have the slightest clue about how this works, but it does :)
// https://stackoverflow.com/questions/11761703/overloading-macro-on-number-of-arguments
#define GELF_DEBUG_GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, NAME, ...) NAME
#define GELF_DEBUG(...) GELF_DEBUG_GET_MACRO(__VA_ARGS__, GELF_DEBUG_8, GELF_DEBUG_7, GELF_DEBUG_6, GELF_DEBUG_5, GELF_DEBUG_4, GELF_DEBUG_3, GELF_DEBUG_2, GELF_DEBUG_1, GELF_DEBUG_SEND)(__VA_ARGS__)

#endif