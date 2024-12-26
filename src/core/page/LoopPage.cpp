#include "LoopPage.hpp"
#include "MenuPage.hpp"
#include <memory>

using Core::Page::LoopPage;

LoopPage::LoopPage(std::shared_ptr<Core::Page::MenuPage> page) : page(page) {}

void LoopPage::execute() {
  while (!this->page->getIsStop()) {
    page->execute();
  }
}
