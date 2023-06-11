// subclasses and fields
#include <iostream>
struct A {
  A() { std::cout << "A"; }
  ~A() { std::cout << "~A"; }
};
struct B: A {
  B() { std::cout << "B"; }
  ~B() { std::cout << "~B"; }
};
struct C: B {
  A a;
  C() { std::cout << "C"; }
  ~C() { std::cout << "~C"; }
};

void f(B b) {}

// Creation of a DerivedN is like this: First -> Base class -> Derived1 -> ... -> DerivedN
// Deletion of a DerivedN is: ~DerivedN -> ~(DerivedN Fields) -> ... -> ~Derived1 -> ~(Derived1 Fields) -> ~Base -> ~(Base Fields)
int main() {
  C c; // Creates an object of C: A<-B<-C:
       // A first (as a subclass) then B (as a subclass)
       // A third (as a field) and finally C
  f(c); // "Converts" C to B
           // then destroys it: ~B ~A
} // Finally : all the other destructors : ~C ~A ~B ~A

// answer : ABAC~B~A~C~A~C