#ifndef Pages_Show_AdvanceOptionShowPage_HPP
#define Pages_Show_AdvanceOptionShowPage_HPP

#include "../../core/page/MenuPage.hpp"

namespace Pages::Show {
class AdvanceOptionShowPage : public Core::Page::MenuPage {
public:
  void configureMenu() override;
};
} // namespace Pages::Show

#endif
