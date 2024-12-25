#include "LoopPage.hpp"
#include "MenuPage.hpp"

using Core::Page::LoopPage;

LoopPage::LoopPage(Core::Page::MenuPage *page) : page(page) {}

void LoopPage::execute() {
  while (!this->page->getIsStop()) {
    page->execute();
  }
}
