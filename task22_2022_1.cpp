template <typename T>
class TalkativeAllocator {
 public:
  using value_type = T;

  TalkativeAllocator() = default;

  T* allocate(size_t n) {
    std::cerr << "method allocate has been called!\n";
    return reinterpret_cast<T*>(new char[n * sizeof(T)]);
  }

  void deallocate(T* ptr, size_t n) {
    std::cerr << "method deallocate has been called!\n";
    delete ptr;
  }

  template <typename... Args>
  void construct(T* ptr, const Args&... args) {
    std::cerr << "method construct has been called!\n";
    new(ptr) T(args...);
  }

  void destroy(T* ptr) {
    std::cerr << "method destroy has been called!\n";
    ptr->~T();
  }
};

// оно вроде даже работает (проверял с std::vector)
