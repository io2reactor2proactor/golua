lua_go:gocalllua.go main.go
	gcc -c call.c -I include/ -L lib/ -llua -lm -ldl
	ar crv libcall.a call.o
	mv libcall.a lib/
	echo "generate lib ok..."
	go build -x -ldflags "-o $@ -w -s" $^
clean:
	rm -rvf lua_go *.o lib/libcall.a
