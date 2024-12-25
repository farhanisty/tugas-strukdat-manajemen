#include "core/page/LoopPage.hpp"
#include "custom/renderer/ModernMenuRenderer.hpp"
#include "pages/MainPage.hpp"
#include <iostream>
#include <locale>

int main() {
  std::wcout.imbue(std::locale("en_US.UTF-8"));

  Pages::MainPage *mainPage = new Pages::MainPage();
  auto basicRenderer = mainPage->getRenderer();

  Custom::Renderer::ModernMenuRenderer *modernMenuRenderer =
      new Custom::Renderer::ModernMenuRenderer("MENU MANAJEMEN TOKO");

  delete basicRenderer;

  mainPage->changeRenderer(modernMenuRenderer);

  Core::Page::LoopPage *loopPage = new Core::Page::LoopPage(mainPage);

  loopPage->execute();

  delete loopPage;
  return 0;
}
