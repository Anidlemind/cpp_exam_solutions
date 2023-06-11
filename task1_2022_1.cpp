#include <iostream>
int main() {
  int i = 1; int j = 1; int k = 1; // simple definitions
  std::cout << (++i || ++j && ++k); // how does this work? simply put:
                                    // the compiler "puts" braces around the &&
                                    // and only then tries to compute the result
                                    // it computes from left to right so ++i is the first one
                                    // it sees that it converts to True as a bool value
                                    // so it stops and prints 1
  std::cout << i << j << k; // here, as i was the only one increased it prints 211
}
// answer - 1211