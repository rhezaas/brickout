#ifndef ALIAS_FUNCTION
#define ALIAS_FUNCTION(OriginalnamE, AliasnamE) \
template <typename... Args> \
inline auto AliasnamE(Args&&... args) -> decltype(OriginalnamE(std::forward<Args>(args)...)) { \
  return OriginalnamE(std::forward<Args>(args)...); \
}

#endif