#ifndef Core_Page_MenuLoopPage_HPP
#define Core_Page_MenuLoopPage_HPP

#include "CanLoopPage.hpp"
#include "MenuPage.hpp"
namespace Core::Page {
class MenuLoopPage : public MenuPage, public CanLoopPage {
public:
  void execute() override { MenuPage::execute(); }
};
} // namespace Core::Page

#endif
