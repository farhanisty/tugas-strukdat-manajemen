#include "ShowPage.hpp"
#include "../../core/page/ExitPage.hpp"
#include "../../custom/renderer/ModernMenuRenderer.hpp"
#include "../../repositories/ProductRepositoryFactory.hpp"
#include "../util/PausePage.hpp"
#include "../util/ShowProductPage.hpp"
#include "AdvanceOptionShowPage.hpp"
#include <iomanip>
#include <iostream>
#include <vector>

using Pages::Show::ShowPage, std::cout, Pages::Util::PausePage;

void ShowPage::execute() {
  this->clearScreen();
  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  std::vector<Entity::Product *> products = productRepository->getAll();

  Util::ShowProductPage *showProductPage = new Util::ShowProductPage(products);
  this->renderPageDirectly(showProductPage);

  AdvanceOptionShowPage *advanceOptionShowPage = new AdvanceOptionShowPage();
  auto tempRenderer = advanceOptionShowPage->getRenderer();

  delete tempRenderer;

  advanceOptionShowPage->changeRenderer(
      new Custom::Renderer::ModernMenuRenderer("OPSI LANJUTAN"));

  this->renderPageDirectly(advanceOptionShowPage);
}
