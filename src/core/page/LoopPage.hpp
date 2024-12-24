#ifndef Core_Page_LoopPage_HPP
#define Core_Page_LoopPage_HPP

#include "CanLoopPage.hpp"
#include "MenuPage.hpp"
#include "Page.hpp"

namespace Core::Page {
class LoopPage : public Page {
  MenuPage *page = nullptr;

public:
  LoopPage(MenuPage *page);
  void execute();
};
} // namespace Core::Page

#endif
