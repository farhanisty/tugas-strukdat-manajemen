#include "core/page/LoopPage.hpp"
#include "custom/renderer/ModernMenuRenderer.hpp"
#include "pages/MainPage.hpp"
#include <memory>

int main() {
  std::shared_ptr<Pages::MainPage> mainPage =
      std::make_shared<Pages::MainPage>();

  mainPage->changeRenderer(
      std::make_shared<Custom::Renderer::ModernMenuRenderer>(
          "MENU MANAJEMEN TOKO"));

  std::shared_ptr<Core::Page::LoopPage> loopPage =
      std::make_shared<Core::Page::LoopPage>(mainPage);

  loopPage->execute();
}
