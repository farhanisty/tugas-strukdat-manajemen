#include "MustNumericConstraint.hpp"
#include "../../core/constraint/Constraint.hpp"
#include "../../core/constraint/ErrorBag.hpp"
#include <string>

using Custom::Constraint::MustNumericConstraint;

MustNumericConstraint::MustNumericConstraint() {
  this->setMessage("Input harus bertipe numerik");
}
bool MustNumericConstraint::check(std::string target,
                                  Core::Constraint::ErrorBag *errorBag) {
  try {
    stof(target);
    return Core::Constraint::Constraint<std::string>::check(target, errorBag);
  } catch (...) {
    errorBag->push(this->getMessage());
    return false;
  }
}
