// _Z3foodl
int foo(double, long) {
    return 0;
}

// bar
extern "C" int bar(double, long) {
    return 0;
}

extern "C" typedef void FUNC();

// baz
FUNC* baz = nullptr;
// buzz
extern "C" FUNC* buzz = nullptr;

extern "C" {
struct C {
    // _ZN1C3memEPFvvE
    void mem(void (*)());
};
}

void C::mem(void (*)()) {}

struct D {
    // _ZN1D6mem_fnEPFvvE
    void mem_fn(void (*)());
};

void D::mem_fn(void (*)()) {}

int main() {
    return 0;
}
