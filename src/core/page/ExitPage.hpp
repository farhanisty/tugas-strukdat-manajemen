#ifndef Core_Page_ExitPage_HPP
#define Core_Page_ExitPage_HPP

#include "MenuPage.hpp"
#include "Page.hpp"

namespace Core::Page {
class ExitPage : public Page {
  MenuPage *page;

public:
  void execute() override {}
};
} // namespace Core::Page

#endif
