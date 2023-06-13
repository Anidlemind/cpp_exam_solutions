template <typename TP, typename T, class... Types>
struct is_any_of {
  static const bool value = std::is_same<TP, T>() or is_any_of<TP, Types...>::value;
};

template <typename TP, typename T>
struct is_any_of<TP, T> {
  static const bool value = std::is_same<TP, T>();
};
