#include "core/page/LoopPage.hpp"
#include "pages/MainPage.hpp"
#include <iostream>

int main() {
  Pages::MainPage *mainPage = new Pages::MainPage();
  Core::Page::LoopPage *loopPage = new Core::Page::LoopPage(mainPage);

  loopPage->execute();

  delete loopPage;
  return 0;
}
