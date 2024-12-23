#ifndef Core_Page_ExitPage_HPP
#define Core_Page_ExitPage_HPP

#include "CanLoopPage.hpp"
#include "Page.hpp"

namespace Core::Page {
class ExitPage : public Page {
  CanLoopPage *page;

public:
  ExitPage(CanLoopPage *page) : page(page) {}
  void execute() override { page->setStop(); }
};
} // namespace Core::Page

#endif
