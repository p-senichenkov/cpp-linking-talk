# Inter-language linking example

This example shows how to link together programs written in different languages through C interface

## C++ -> Go

Calee is written in C++ (`cpplib.h` and `cpplib.cpp`), caller is written in Go (`go-main.go`)

### Running

Compile C++ library with
```bash
g++ -std=c++20 -shared -fPIC cpplib.cpp -o libs/libcpplib.so
```

Build and run Go program with
```bash
go build go-main.go && ./go-main
```
