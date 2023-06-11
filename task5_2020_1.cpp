//virtual understanding question (wtf?)
#include <iostream>
struct Base {
  virtual void f() { std::cout << 1; } // as this is virtual it will be overwritten by the
                                       // derived class (if virtual is deleted it will not be
                                       // overwritten)
};
struct Derived: public Base {
  virtual void f() { std::cout << 2; } // nothing to be derived so it's not overwritten
};
int main() {
  Derived d; // creates Derived with a subclass of Base
  d.f(); // as Derived.f() overwrites Base.f() it is called. : 2
  static_cast<Base&>(d).f(); // d is cast into Base as it has a subclass B.
                             // as cpp reference states: reference-calling calls
                             // the overwritten virtual function. : 2
}
// answer : 22