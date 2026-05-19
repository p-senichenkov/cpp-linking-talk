package main

// #cgo LDFLAGS: -L${SRCDIR}/libs -lcpplib -Wl,-rpath,${SRCDIR}/libs
// #include "cpplib.h"
import "C"
import (
	"fmt"
	"math/rand"
)

func main() {
	arr := make([]int32, 15)
	for i := range arr {
		arr[i] = int32(rand.Int())
	}
	fmt.Print("Initial range: ")
	for _, el := range arr {
		fmt.Print(el, " ")
	}
	fmt.Println()

	C.sort_range((*C.int)(&arr[0]), (*C.int)(&arr[len(arr)-1]))
	fmt.Print("Sorted range: ")
	for _, el := range arr {
		fmt.Print(el, " ")
	}
	fmt.Println()
}
