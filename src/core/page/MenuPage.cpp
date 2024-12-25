#include "MenuPage.hpp"
#include "../constraint/MustInRangeConstraint.hpp"
#include "../constraint/MustIntegerConstraint.hpp"
#include "../input/Input.hpp"
#include "../input/InputBuilder.hpp"
#include "../renderer/BasicInputMenuRenderer.hpp"
#include "../renderer/BasicMenuRenderer.hpp"
#include "../renderer/MenuRenderer.hpp"
#include "string"

using Core::Input::InputBuilder, Core::Constraint::MustIntegerConstraint,
    Core::Page::MenuPage;

MenuPage::MenuPage() {
  this->menuRenderer = new Renderer::BasicMenuRenderer();
  // this->inputRenderer = new Renderer::BasicInputMenuRenderer();
}

bool MenuPage::getIsStop() { return this->isStop; }
void MenuPage::setIsStop(bool isStop) { this->isStop = isStop; }
void MenuPage::setStop() { this->setIsStop(true); }

void MenuPage::changeRenderer(Renderer::MenuRenderer *menuRenderer) {
  this->menuRenderer = menuRenderer;
}

Core::Renderer::MenuRenderer *MenuPage::getRenderer() {
  return this->menuRenderer;
}

void Core::Page::MenuPage::addMenu(std::string label, Page *page) {
  this->pageItems.push_back(new PageItem(label, page));
}

// void MenuPage::changeInputRenderer(Renderer::InputMenuRenderer
// *inputRenderer) {
//   this->inputRenderer = inputRenderer;
// }
//
// Core::Renderer::InputMenuRenderer *MenuPage::getInputRenderer() {
//   return this->inputRenderer;
// }

void Core::Page::MenuPage::execute() {
  if (!this->isConfigured) {
    this->configureMenu();
    this->isConfigured = true;
  }

  this->before();

  this->menuRenderer->render(this->pageItems);

  InputBuilder inputBuilder;
  inputBuilder.setPrefix("Masukkan input anda > ")
      ->setConstraint(new MustIntegerConstraint())
      ->setConstraint(
          new Constraint::MustInRangeConstraint(1, this->pageItems.size()));

  Input::Input *input = inputBuilder.build();

  input->execute();

  while (!input->isValid()) {
    std::cout << input->getErrorBag()->getErrors()[0] << "\n";
    input->execute();
  }

  // Input::Input *input = this->inputRenderer->render(this->pageItems.size());

  int resultInput = stoi(input->getRawInput());

  this->pageItems[resultInput - 1]->page->execute();

  this->after();
}

std::string Core::Page::MenuPage::getInput() { return this->input; }

void Core::Page::MenuPage::after() {}

Core::Page::MenuPage::~MenuPage() {
  for (auto p : this->pageItems) {
    delete p;
  }
}
