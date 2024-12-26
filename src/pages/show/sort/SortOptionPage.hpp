#ifndef Pages_Show_Sort_SortOptionPage_HPP
#define Pages_Show_Sort_SortOptionPage_HPP

#include "../../../core/page/MenuPage.hpp"

namespace Pages::Show::Sort {
class SortOptionPage : public Core::Page::MenuPage {
public:
  void configureMenu() override;
};
} // namespace Pages::Show::Sort

#endif
