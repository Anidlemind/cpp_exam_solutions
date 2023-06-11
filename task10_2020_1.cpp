//realization of move-constructor and move-operator=
#include <iostream>

class String {
  char* arr;
  size_t sz;
  size_t cap;

  String(String&& other) : arr(nullptr),
                           sz(0),
                           cap(0) {
    std::swap(arr, other.arr);
    std::swap(sz, other.sz);
    std::swap(cap, other.cap);
  }

  String& operator=(String&& other) {
    if (this == &other) {
      return *this;
    }
    arr = nullptr;
    sz = 0;
    cap = 0;
    std::swap(arr, other.arr);
    std::swap(sz, other.sz);
    std::swap(cap, other.cap);
    return *this;
  }
};