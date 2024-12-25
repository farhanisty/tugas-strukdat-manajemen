#ifndef Pages_Show_ShowPage_HPP
#define Pages_Show_ShowPage_HPP

#include "../../core/page/MenuPage.hpp"
#include "../../core/page/Page.hpp"

namespace Pages::Show {
class ShowPage : public Core::Page::MenuPage {
public:
  void configureMenu() override;
  void before() override;
};
} // namespace Pages::Show

#endif
