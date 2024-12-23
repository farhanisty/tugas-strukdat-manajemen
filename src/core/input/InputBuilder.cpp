#include "InputBuilder.hpp"
#include "Input.hpp"

using Core::Input::InputBuilder, Core::Input::Input;

Input *InputBuilder::getInstance() {
  if (this->result == nullptr) {
    this->result = new Input();
  }

  return this->result;
}

InputBuilder *InputBuilder::setPrefix(string prefix) {
  this->getInstance()->setPrefix(prefix);
  return this;
}

InputBuilder *InputBuilder::setConstraint(::Constraint<string> *constraint) {
  if (this->lastConstraint == nullptr) {
    this->getInstance()->setConstraint(constraint);
  } else {
    this->lastConstraint->setNext(constraint);
  }

  this->lastConstraint = constraint;

  return this;
}

void InputBuilder::fresh() {
  this->result = nullptr;
  this->lastConstraint = nullptr;
}

Input *InputBuilder::build() { return this->result; }
