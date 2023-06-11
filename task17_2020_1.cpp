// casts!
#include <iostream>

template<typename T>
class MyClass {
  T x;

 public:
  MyClass() = default;
};
int main() {
  MyClass<int> a{};
  static_cast<MyClass<float>>(a); // Nope, static cast for classes only works if:
                                  // 1. There is a derived and a base class : Derived -> Base!
                                  // 2. There is a constructor! (MyClass<float>(MyClass<int>)
                                  // 3. There is a defined conversion! (operator MyClass<float>())
  dynamic_cast<MyClass<float>>(a); // Only references and pointers allowed!
                                   // Also, here is some things to keep in mind:
                                   // 1. Can work with adding constness
                                   // 2. Convert nullptr into any other pointer
                                   // 3. Derived-ptr -> Base-ptr
                                   // 4. Polymorphic -> void (I don't know how it works)
                                   // 5. Some other Polymorphic bullshit.
  reinterpret_cast<MyClass<float>>(a); // No constness castaway!!!
                                       // But that's not the reason
                                       // This bs mainly works with pointers and integral
                                       // or enumerate types, so...
}