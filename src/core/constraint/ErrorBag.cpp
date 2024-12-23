#include "ErrorBag.hpp"

void Core::Constraint::ErrorBag::push(std::string error) {
  this->errors.push_back(error);
}

std::vector<std::string> Core::Constraint::ErrorBag::getErrors() {
  return this->errors;
}

bool Core::Constraint::ErrorBag::isAny() { return this->errors.size() > 0; }
