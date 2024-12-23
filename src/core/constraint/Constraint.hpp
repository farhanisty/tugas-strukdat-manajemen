#ifndef Core_Constraint_Constraint_HPP
#define Core_Constraint_Constraint_HPP

#include "ErrorBag.hpp"
#include <string>

namespace Core::Constraint {

template <typename T> class Constraint {
  Constraint<T> *next = nullptr;
  std::string message = "";

public:
  virtual void setMessage(std::string message) { this->message = message; }

  virtual std::string getMessage() { return this->message; }

  virtual bool hasNext() { return this->next != nullptr; }

  virtual Constraint<T> *getNext() { return this->next; }

  virtual Constraint *setNext(Constraint *next) {
    this->next = next;
    return this;
  }

  virtual bool check(T target, ErrorBag *errorBag) {
    if (this->next == nullptr) {
      return true;
    }

    return this->next->check(target, errorBag);
  }
};

} // namespace Core::Constraint

#endif
