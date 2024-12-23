#ifndef Core_Page_LoopPage_HPP
#define Core_Page_LoopPage_HPP

#include "CanLoopPage.hpp"
#include "Page.hpp"

namespace Core::Page {
class LoopPage : public Page {
  CanLoopPage *page = nullptr;

public:
  LoopPage(CanLoopPage *page);
  void execute();
};
} // namespace Core::Page

#endif
