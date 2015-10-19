package main

//#include <stdio.h>
//#include <stdlib.h>
//#include "lua.h"
//#include "call.h"
//#cgo CFLAGS: -I include/
//#cgo LDFLAGS: -L lib/ -lcall -llua -lm -ldl
import "C"

func OpenLua() *C.lua_State {
	return C.open_lua()
}

func CloseLua(L *C.lua_State) {
	C.close_lua(L)
}

func CallLua(L *C.lua_State, filename string) bool {
	script_filename := C.CString(filename)
	ret := C.call_lua(L, script_filename)
	if int(ret) == 0 {
		return true
	}
	return false
}
