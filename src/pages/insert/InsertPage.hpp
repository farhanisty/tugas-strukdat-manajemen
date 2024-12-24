#ifndef Pages_InsertPage_HPP
#define Pages_InsertPage_HPP

#include "../../core/page/MenuPage.hpp"

namespace Pages::Insert {

class InsertPage : public Core::Page::MenuPage {
public:
  void configureMenu() override;

  void before() override;
};

} // namespace Pages::Insert

#endif
