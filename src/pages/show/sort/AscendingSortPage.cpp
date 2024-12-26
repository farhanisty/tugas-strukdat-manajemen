#include "AscendingSortPage.hpp"
#include "../../../custom/renderer/ModernMenuRenderer.hpp"
#include "../../../repositories/ProductRepositoryFactory.hpp"
#include "../../util/ShowProductPage.hpp"
#include "../AdvanceOptionShowPage.hpp"
#include <iostream>

using Pages::Show::Sort::AscendingSortPage;

void AscendingSortPage::execute() {
  this->clearScreen();
  std::cout << "LIST PRODUK TERURUT SECARA ASCENDING\n";

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
