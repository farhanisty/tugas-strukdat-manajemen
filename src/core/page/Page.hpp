#ifndef Core_Page_HPP
#define Core_Page_HPP

#include <iostream>

namespace Core::Page {

class Page {
public:
  virtual void execute() = 0;
  virtual ~Page() {}

  void renderPageDirectly(Page *page) {
    page->execute();
    delete page;
  }

  void clearScreen() {
#if __unix__
    system("clear");
#else
    system("cls");
#endif
  }
};

} // namespace Core::Page

#endif
