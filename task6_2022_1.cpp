#include <vector>
#include <iostream>
int main() {
  std::vector<int> v = {1, 2, 3};
  try {
    for (int i = 0; i < 5; ++i) {
      std::cout << v[i]; // operator[] is not exception-safe, so it does not throw!
                         // no exceptions will be thrown! As we are not so far from the
                         // allocated memory it is not RE
    }
  } catch (std::out_of_range& ex) { // no exception - no catching!
    std::cout << "AAA";
  } catch (...) { // no exception - no catching!
    std::cout << "BBB";
  }
}
// answer : UB