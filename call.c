/*#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>*/
#include "call.h"

lua_State* open_lua()
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	//lua_register(L, "csum", csum);
	return L;
}

void close_lua(lua_State* L)
{
	lua_close(L);
	return;
}

int call_lua(lua_State *L, char* filename)
{
	if(L == NULL || filename == NULL)
	{
		printf("L or filename is NULL\n");
		return;
	}

	if(luaL_dofile(L, filename) == LUA_OK)
	{
		printf("luaL_dofile is ok\n");
		return 0;
	}
	printf("luaL_dofile is error\n");
	return 1;
}

//gcc -g -o aaa t.c  liblua.a -lm -ldl
//gcc -c call.c 
//ar crv libcall.a call.o
