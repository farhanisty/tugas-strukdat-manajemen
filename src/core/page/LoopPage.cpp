#include "LoopPage.hpp"

using Core::Page::LoopPage;

LoopPage::LoopPage(CanLoopPage *page) : page(page) {}

void LoopPage::execute() {
  while (!this->page->getIsStop()) {
    page->execute();
  }
}
