#ifndef Pages_Show_Filter_FilterMainPage_HPP
#define Pages_Show_Filter_FilterMainPage_HPP

#include "../../../core/page/MenuPage.hpp"

namespace Pages::Show::Filter {
class FilterMainPage : public Core::Page::MenuPage {
public:
  void configureMenu() override;
};
} // namespace Pages::Show::Filter

#endif
