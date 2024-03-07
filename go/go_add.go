package main

// go build -ldflags "-s -w" -o ./go/go_add.dll -buildmode=c-shared ./go/go_add.go

//#cgo CFLAGS: -Os
import "C"

//export Add
func Add(a, b C.int) C.int {
	println("dll::go_add", a, b)
	return C.int(int(a) + int(b))
}

func main() {}