#ifndef Core_Constraint_ErrorBag_HPP
#define Core_Constraint_ErrorBag_HPP

#include <string>
#include <vector>

namespace Core::Constraint {

class ErrorBag {
  std::vector<std::string> errors;

public:
  void push(std::string error);
  std::vector<std::string> getErrors();
  bool isAny();
};

} // namespace Core::Constraint

#endif
