#ifndef Core_Constraint_MustIntegerConstraint_HPP
#define Core_Constraint_MustIntegerConstraint_HPP

#include "Constraint.hpp"
#include <string>

namespace Core::Constraint {

class MustIntegerConstraint : public Constraint<std::string> {
public:
  MustIntegerConstraint();

  bool check(std::string target, ErrorBag *errorBag) override;
};
} // namespace Core::Constraint

#endif
