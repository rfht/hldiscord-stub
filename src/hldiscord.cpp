#define HL_NAME(n) discord_##n
#include <hl.h>
#include <time.h>


void Ready(const int* request) {
}

void Disconnected(int _errorCode, const char* _message) {
}

void Errored(int _errorCode, const char* _message) {
}

static int presence;
static bool init = false;
HL_PRIM bool HL_NAME(init)(vbyte* _appID, vbyte* _steamID){
    return true;
}

HL_PRIM void HL_NAME(update_presence)() {
}

HL_PRIM void HL_NAME(release)() {
}

// for Darksburg
HL_PRIM void HL_NAME(send_request_reply)() { }
HL_PRIM void HL_NAME(update_activity)() { }
HL_PRIM bool HL_NAME(register_steam)() { return false; }
HL_PRIM void HL_NAME(loop)() { }

#define IMPLEMENT_PRESENCE_PROPERTY_UPDATE(paramName, type)     \
void update_##paramName(type _value, bool _autoSend) {          \
}                                                               \

#define IMPLEMENT_PRESENCE_STRING_PROPERTY_UPDATE(paramName)                \
IMPLEMENT_PRESENCE_PROPERTY_UPDATE(paramName, const char*)                  \
HL_PRIM void HL_NAME(update_##paramName)(vbyte* _value, bool _autoSend){    \
}                                                                           \
DEFINE_PRIM(_VOID, update_##paramName, _BYTES _BOOL)

#define IMPLEMENT_PRESENCE_INTEGER_PROPERTY_UPDATE(paramName)               \
IMPLEMENT_PRESENCE_PROPERTY_UPDATE(paramName, int)                          \
HL_PRIM void HL_NAME(update_##paramName)(int _value, bool _autoSend){       \
}                                                                           \
DEFINE_PRIM(_VOID, update_##paramName, _I32 _BOOL)


IMPLEMENT_PRESENCE_STRING_PROPERTY_UPDATE(state)
IMPLEMENT_PRESENCE_STRING_PROPERTY_UPDATE(details)
IMPLEMENT_PRESENCE_STRING_PROPERTY_UPDATE(largeImageKey)
IMPLEMENT_PRESENCE_STRING_PROPERTY_UPDATE(largeImageText)
IMPLEMENT_PRESENCE_STRING_PROPERTY_UPDATE(smallImageKey)
IMPLEMENT_PRESENCE_STRING_PROPERTY_UPDATE(smallImageText)
IMPLEMENT_PRESENCE_STRING_PROPERTY_UPDATE(matchSecret)
IMPLEMENT_PRESENCE_STRING_PROPERTY_UPDATE(joinSecret)
IMPLEMENT_PRESENCE_STRING_PROPERTY_UPDATE(spectateSecret)

IMPLEMENT_PRESENCE_INTEGER_PROPERTY_UPDATE(partySize)
IMPLEMENT_PRESENCE_INTEGER_PROPERTY_UPDATE(partyMax)
IMPLEMENT_PRESENCE_INTEGER_PROPERTY_UPDATE(startTimestamp)
IMPLEMENT_PRESENCE_INTEGER_PROPERTY_UPDATE(endTimestamp)

DEFINE_PRIM(_VOID, init, _BYTES _BYTES)
DEFINE_PRIM(_VOID, release, _NO_ARG)
DEFINE_PRIM(_VOID, send_request_reply, _NO_ARG)		// for Darksburg
DEFINE_PRIM(_VOID, update_activity, _NO_ARG)		// for Darksburg
DEFINE_PRIM(_BOOL, register_steam, _NO_ARG)		// for Darksburg
DEFINE_PRIM(_VOID, loop, _NO_ARG)		// for Darksburg
