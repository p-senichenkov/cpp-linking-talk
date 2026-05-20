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

To see geenrated C code, run the `cgo` command directly.
Generated code will be in `_obj` directory:
```bash
go tool cgo go-main.go
ls _obj
```

A brief description of files that you will see there:
- `_cgo_export.h` and `_cgo_export.c` -- exported declarations for other C programs that link to our
  Go library
- `_cgo_gotypes.go` -- Go wrappers around C types
- `_cgo_main.c` -- pseudo-main file that is used internally by `cgo` for some checks
- `go-main.cgo1.go` -- what `go-main.go` becomes after expansion of "C" pseudo-package.
  This file is being compiled by Go compiler later
- `go-main.cgo2.c` -- wrappers around included (and used) C functions. Also contains some
  auxillary definitions and assertions
