#ifndef Core_Page_LoopPage_HPP
#define Core_Page_LoopPage_HPP

#include "CanLoopPage.hpp"
#include "MenuPage.hpp"
#include "Page.hpp"

namespace Core::Page {
class LoopPage : public Page {
  std::shared_ptr<MenuPage> page = nullptr;

public:
  LoopPage(std::shared_ptr<MenuPage> page);
  void execute();
};
} // namespace Core::Page

#endif
