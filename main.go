package main

import (
	"flag"
	"fmt"
	"runtime"
	"time"
)

var (
	filename *string = flag.String("f", "hao.lua", "lua script filename")
	workers  *int    = flag.Int("w", 1, "goroutine number")
)

func main() {
	flag.Parse()
	runtime.GOMAXPROCS(runtime.NumCPU())

	fmt.Printf("filename:%s\n", *filename)
	fmt.Printf("workers:%d\n", *workers)

	var fn = *filename
	var num = *workers
	for i := 0; i < num; i++ {
		go run(i, fn)
	}

	time.Sleep(time.Hour * 24)
}

func run(idx int, fn string) {
	L := OpenLua()
	fmt.Printf("goroutine:%d\n", idx)
	if CallLua(L, fn) {
		fmt.Printf("CallLua ok\n")
	} else {
		fmt.Printf("CallLua error\n")
	}
	CloseLua(L)
}
