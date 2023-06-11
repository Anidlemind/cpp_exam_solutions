#include <iostream>
int main() {
  int x = 1;
  const int& y = x;
  int& z = y; // we are trying to make a non-cons reference to a const reference
              // const int& is considering the value under it a const (even if it's not)
              // so we get the "drops const qualifier" error
  ++x;
  std::cout << x << y << z;
}
// answer: CE