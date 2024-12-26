#ifndef Core_MenuPage_HPP
#define Core_MenuPage_HPP

#include "../renderer/InputMenuRenderer.hpp"
#include "../renderer/MenuRenderer.hpp"
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
  std::shared_ptr<Renderer::MenuRenderer> menuRenderer;
  // Renderer::InputMenuRenderer *inputRenderer;

protected:
  std::vector<std::shared_ptr<PageItem>> pageItems;

public:
  MenuPage();
  bool getIsStop();
  void setIsStop(bool isStop);
  void setStop();

  void changeRenderer(std::shared_ptr<Renderer::MenuRenderer> menuRenderer);

  std::shared_ptr<Renderer::MenuRenderer> getRenderer();

  // void changeInputRenderer(Renderer::InputMenuRenderer *inputRenderer);
  //
  // Renderer::InputMenuRenderer *getInputRenderer();

  virtual void configureMenu() = 0;
  virtual void before() {};
  virtual void after();

  void addMenu(std::string label, std::shared_ptr<Page> page);
  void execute();
  std::string getInput();

  virtual ~MenuPage() {}
};

} // namespace Core::Page

#endif
