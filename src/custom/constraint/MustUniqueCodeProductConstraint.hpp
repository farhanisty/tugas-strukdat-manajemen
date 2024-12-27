#ifndef Custom_Constraint_MustUniqueCodeProductConstraint_HPP
#define Custom_Constraint_MustUniqueCodeProductConstraint_HPP

#include "../../core/constraint/Constraint.hpp"
#include "../../core/constraint/ErrorBag.hpp"

namespace Custom::Constraint {
class MustUniqueCodeProductConstraint
    : public Core::Constraint::Constraint<std::string> {
public:
  MustUniqueCodeProductConstraint();
  bool check(std::string target, Core::Constraint::ErrorBag *errorBag) override;
};
} // namespace Custom::Constraint

#endif
