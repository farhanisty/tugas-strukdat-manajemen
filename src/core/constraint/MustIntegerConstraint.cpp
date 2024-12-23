#include "MustIntegerConstraint.hpp"

using Core::Constraint::MustIntegerConstraint;

MustIntegerConstraint::MustIntegerConstraint() {
  this->setMessage("Input harus integer");
}

bool MustIntegerConstraint::check(std::string target, ErrorBag *errorBag) {
  for (char c : target) {
    if ((int)c < 48 || (int)c > 57) {
      errorBag->push(this->getMessage());
      return false;
    }
  }
  return Constraint::check(target, errorBag);
}
