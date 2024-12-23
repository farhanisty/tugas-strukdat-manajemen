#ifndef Core_Constraint_MustFixSizeConstraint_HPP
#define Core_Constraint_MustFixSizeConstraint_HPP

#include "Constraint.hpp"
#include <string>

namespace Core::Constraint {
class MustInRangeConstraint : public Constraint<std::string> {
  int min;
  int max;

public:
  MustInRangeConstraint(int min, int max);

  bool check(std::string target, ErrorBag *errorBag) override;
};
} // namespace Core::Constraint

#endif
