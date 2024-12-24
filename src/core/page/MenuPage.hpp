#ifndef Core_MenuPage_HPP
#define Core_MenuPage_HPP

#include "Page.hpp"
#include "PageItem.hpp"
#include "string"
#include "vector"

namespace Core::Page {

class MenuPage : public Page {
private:
  bool isStop = false;
  std::string input = "";
  bool isConfigured = false;

protected:
  std::vector<PageItem *> pageItems;

public:
  bool getIsStop();
  void setIsStop(bool isStop);
  void setStop();
  virtual void configureMenu() = 0;
  virtual void before() {};
  virtual void after();

  void addMenu(std::string label, Page *page);
  void execute();
  std::string getInput();

  virtual ~MenuPage();
};

} // namespace Core::Page

#endif
