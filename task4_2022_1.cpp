// this task is actually fucked up

#include <iostream>
class A {
public:
  A() { std::cout << 0; }
  A(A&) { std::cout << 1; }
  A operator=(A&) { std::cout << 2; return *this; } // compiler kinda shows a hint
                                                    // you may not notice it at first
                                                    // but this returns a non-reference object!
  ~A() { std::cout << 3; }
};
int main() {
  A a; // simple default constructor : 0
  A b = a; // this is a copy-constructor! : 1
  a = b; // this is the fucked up part!
         // it calls in operator= : 2
         // then it realises "oh, fuck, this returns a non-reference object"
         // so the result of the function creates an object and calls a copy-constructor
         // using the created object, creating a reference of it: 1
         // the created reference and object are then destroyed
         // as it has done it's job : 3
} // now we destroy all the other things ! : 33
// answer: 0121333

// (proof of the point in a=b is simply adding another one! it generates another triple of 213)