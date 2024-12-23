#ifndef Input_HPP
#define Input_HPP

#include "../constraint/Constraint.hpp"
#include "../constraint/ErrorBag.hpp"
#include <iostream>
#include <string>

using Core::Constraint::Constraint;
using Core::Constraint::ErrorBag;

namespace Core::Input {

class Input {
  ::Constraint<std::string> *constraint = nullptr;
  ::ErrorBag *errorBag = nullptr;
  std::string rawInput = "";
  std::string prefix = "";

public:
  void execute(bool isLine = false) {
    if (this->prefix != "") {
      std::cout << this->prefix;
    }

    if (isLine) {
      std::cin.ignore();

      std::getline(std::cin, rawInput);
    } else {
      std::cin >> rawInput;
    }

    if (this->constraint == nullptr) {
      return;
    }

    ErrorBag *errorBag = new ErrorBag();

    this->constraint->check(rawInput, errorBag);

    this->errorBag = errorBag;
  }

  void setPrefix(std::string prefix) { this->prefix = prefix; }

  ErrorBag *getErrorBag() { return this->errorBag; }

  std::string getRawInput() { return this->rawInput; }

  void setConstraint(::Constraint<std::string> *constraint) {
    this->constraint = constraint;
  }

  ::Constraint<std::string> *getConstraint() const { return this->constraint; }

  bool isValid() {
    if (this->errorBag == nullptr) {
      return true;
    }

    if (!this->errorBag->isAny()) {
      return true;
    }

    return false;
  }

  ~Input() {
    auto temp = this->constraint;
    while (temp != nullptr) {
      auto del = temp;

      temp = temp->getNext();

      delete del;
    }

    delete this->errorBag;
  }
};
} // namespace Core::Input

#endif
