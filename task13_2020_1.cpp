// -O2 infinite cycle
#include <iostream>
int main() {
  for (int i = 0; i < 300; ++i) {
    std::cout << i << ' ' << i*12345678 << std::endl; // O2 thinks: ok, there is no overflow
                                                      // so i <= 174, so the i < 300 can be ignored
  }
}