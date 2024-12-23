#include "MustInRangeConstraint.hpp"

using Core::Constraint::MustInRangeConstraint;

MustInRangeConstraint::MustInRangeConstraint(int min, int max)
    : min(min), max(max) {
  this->setMessage("Input harus berada di antara " + std::to_string(this->min) +
                   " dan " + std::to_string(this->max));
}

bool MustInRangeConstraint::check(std::string target, ErrorBag *errorBag) {
  if (stoi(target) < min || stoi(target) > max) {
    errorBag->push(this->getMessage());

    return false;
  }

  return Constraint::check(target, errorBag);
}
