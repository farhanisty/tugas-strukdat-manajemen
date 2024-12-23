#ifndef Core_Input_InputBuilder_HPP
#define Core_Input_InputBuilder_HPP

#include "../constraint/Constraint.hpp"
#include "Input.hpp"
#include <string>

using Core::Constraint::Constraint, std::string;

namespace Core::Input {

class InputBuilder {
  Input *result = nullptr;
  ::Constraint<string> *lastConstraint = nullptr;

  Input *getInstance();

public:
  InputBuilder *setPrefix(string prefix);

  InputBuilder *setConstraint(::Constraint<string> *constraint);

  void fresh();

  Input *build();
};

} // namespace Core::Input
#endif
