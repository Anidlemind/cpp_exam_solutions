// i kinda don't know how shared_ptr works so this might be wrong
#include <memory>
#include <iostream>
int main() {
  std::shared_ptr<int> p(new int(1)); // creates a shared_ptr of a dynamic pointer to 1
  std::shared_ptr<int> pp(new int(2)); // creates a shared_ptr of a dynamic pointer to 2
  p = pp; // what happens here? the pointer to 1 is destroyed and pointer to 2 is assigned
          // it's yet another pointer to 2, so use_count is up by 1!
  std::cout << p.use_count() << pp.use_count(); // 2 and 2 as they now both point to 2.
  std::cout << *p << *pp; // 2 and 2 by the same reasoning
}
// answer : 2222