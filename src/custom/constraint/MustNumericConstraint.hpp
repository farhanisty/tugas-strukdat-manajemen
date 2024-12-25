#ifndef Custom_Constraint_MustNumericConstraint_HPP
#define Custom_Constraint_MustNumericConstraint_HPP

#include "../../core/constraint/Constraint.hpp"
#include "../../core/constraint/ErrorBag.hpp"

namespace Custom::Constraint {
class MustNumericConstraint : public Core::Constraint::Constraint<std::string> {
public:
  MustNumericConstraint();
  bool check(std::string target, Core::Constraint::ErrorBag *errorBag) override;
};
} // namespace Custom::Constraint

#endif
