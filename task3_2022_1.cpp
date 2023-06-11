#include <iostream>
int& max(int x, int y) {
  return x > y ? x : y;
}
int main() {
  int x = 2;
  int y = 3;
  std::cout << max(x, y); // seems sus? that's because it kinda is
                          // reference may actually throw you off but it's  fine
                          // i kinda thought that the return value of the function
                          // dies after it's out of the local visibility so reference is dead
                          // but i was wrong. assuming it returns a reference, we know that
                          // a reference to an object in local visibility expands it's life span
                          // to the last moment it's in use. So it's ok!
}
// answer: 3