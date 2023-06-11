// which of these definitions are errors?
#include <iostream>

int main() {
  int& a = 5; // can't handle a reference to a rvalue
  const int& b = 5; // reference to a constant, OK!
  int& const c = 5; // no such thing as a constant reference + can't handle a reference to a rvalue
  int&& d = 5; // rvalue reference to a rvalue, OK!
  int const&& e = 5; // rvalue reference to a rvalue (constant one - can't be changed)
                     // e = 6 would result in an error
  int& f = d; // reference to a variable (a lvalue!) OK!
  int&& h = b; // trying to create rvalue reference to a lvalue!
  int&& g = d; // trying to create rvalue reference to a lvalue!
}