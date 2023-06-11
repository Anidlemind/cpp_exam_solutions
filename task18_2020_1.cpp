// What are the problems of this code?
// Will it compile?
// How to solve these problems?
#include <iostream>
#include <map>

void print_map(const std::map<int, int>& m) { // keys in a map should be const types (<const int, ...>)
  for (std::pair<int, int>& p: m) { // first of all: const throw-away! should be const std::pair...
    std::cout << p->first << ' ' << p->second << '\n'; // second of all: wtf? you cant use -> to a reference. Should be "."
  }
}