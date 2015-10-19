/*#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>*/
#include "call.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	lua_State* L;
	if(argc < 2)
	{
		printf("Usage: <script-filename>\n");
		return -1;
	}
	
	L = open_lua();
	if(1 == call_lua(L, argv[1]))
	{
		printf("call_lua error\n");
	}
	printf("call_lua ok\n");
	close_lua(L);
}