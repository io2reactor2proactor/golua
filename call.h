#ifndef CALL_H
#define CALL_H

#include "lua.hpp"

lua_State* open_lua();
int call_lua(lua_State*, char*);
void close_lua(lua_State*);
#endif
