#ifndef Core_Page_ClearScreenPage_HPP
#define Core_Page_ClearScreenPage_HPP

#include "Page.hpp"

namespace Core::Page {
class ClearScreenPage : public Page {

public:
  void execute() override {
#ifdef __unix__
    system("clear");
#else
    system("cls");
#endif
  }
};
} // namespace Core::Page

#endif
