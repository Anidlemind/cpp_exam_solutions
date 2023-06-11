// realisation of std::unique
#include <iterator>

using namespace std;

template<typename T, class Compare_Equal>
std::iterator<std::forward_iterator_tag, T> unique(std::iterator<std::forward_iterator_tag, T> begin, std::iterator<std::forward_iterator_tag, T> end, Compare_Equal comp) {
  if (begin == end) {
    return end + 1;
  }
  auto available = begin;
  while (++begin != end) {
    if (!comp(*available, *begin) && (++available != begin)) {
      *available = std::move(*begin);
    }
  }
  return ++available;
}