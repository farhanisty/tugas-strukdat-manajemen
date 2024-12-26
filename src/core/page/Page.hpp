#ifndef Core_Page_HPP
#define Core_Page_HPP

#include <iostream>
#include <memory>

namespace Core::Page {

class Page {
public:
  virtual void execute() = 0;
  virtual ~Page() {}

  void renderPageDirectly(std::shared_ptr<Page> page) { page->execute(); }

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
