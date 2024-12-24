#ifndef Pages_MainPage_HPP
#define Pages_MainPage_HPP

#include "../core/page/MenuPage.hpp"

namespace Pages {

class MainPage : public Core::Page::MenuPage {
public:
  void configureMenu() override;

  void before() override;
};

} // namespace Pages

#endif
