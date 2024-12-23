#ifndef Core_Constraint_MustInRangeConstraint_HPP
#define Core_Constraint_MustInRangeConstraint_HPP

#include "Constraint.hpp"
#include <string>

namespace Core::Constraint {

class MustFixSizeConstraint : public Constraint<std::string> {
  unsigned int fixSize;

public:
  MustFixSizeConstraint(unsigned int fixSize) : fixSize(fixSize) {
    this->setMessage("Input harus memiliki panjang " +
                     std::to_string(this->fixSize));
  }

  bool check(std::string target, ErrorBag *errorBag) override {
    int count = 0;

    for (auto c : target) {
      count++;
    }

    if (count != this->fixSize) {
      errorBag->push(this->getMessage());
      return false;
    }

    return Constraint::check(target, errorBag);
  }
};
} // namespace Core::Constraint

#endif
