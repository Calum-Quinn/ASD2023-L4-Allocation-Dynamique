//FORBIDDEN cout
//FORBIDDEN cerr
//FORBIDDEN printf
//FORBIDDEN puts
//FORBIDDEN putchar
//FORBIDDEN putc
#include "util.h"
#include "c.h"

int cnt = 0; // utilisez cette variable globale

void f0() noexcept {
    enter("f0");
// AJOUTEZ VOTRE CODE ICI ...
   static C c2(++cnt);
   C c34(++cnt);

// ... FIN DE VOTRE CODE
    leave("f0");
}

C* f1() {
    enter("f1");
    C* p;
// AJOUTEZ VOTRE CODE ICI ...
    p = new C(++cnt);
// ... FIN DE VOTRE CODE
    leave("f1");
    return p;
}

C* f2() {
    enter("f2");
    C* p;
// AJOUTEZ VOTRE CODE ICI ...
   C* q = new C[2]{C(++cnt),C(++cnt)};
   p = q;
// ... FIN DE VOTRE CODE
    leave("f2");
    return p;
}

void f3(C* p) noexcept {
    enter("f3");
// AJOUTEZ VOTRE CODE ICI ...
   new((void*)(p)) C{C(++cnt)};
// ... FIN DE VOTRE CODE
    leave("f3");
}

void f4(C* p, size_t n) noexcept {
    enter("f4");
// AJOUTEZ VOTRE CODE ICI ...
	for(size_t i = 0; i < n; i++){
		new (&p[i]) C{++cnt};
	}
// ... FIN DE VOTRE CODE
    leave("f4");
}

int main() {
    enter("main");
// AJOUTEZ VOTRE CODE ICI ...
   C c1(++cnt);
   f0();
   f0();
   C* q = f1();

   C* p = f2();

   void* c8 = ::operator new(sizeof(C));

   f3((C*)(c8));

   delete[] p;
   delete q;

	void* cf4 = ::operator new(2*sizeof(C));

   f4((C*)cf4,2);

	delete (C*)(c8);

	void* cf4_2 = ::operator new(sizeof(C));
	f4((C*)cf4_2,1);

	for(size_t i = 0; i < 2; ++i){
		(((C*)cf4)[i]).~C();
	}

	::operator delete(cf4);

   delete (C*)cf4_2;


// ... FIN DE VOTRE CODE
    leave("main");
}
