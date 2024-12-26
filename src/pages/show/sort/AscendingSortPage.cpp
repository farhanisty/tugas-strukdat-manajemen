#include "AscendingSortPage.hpp"
#include "../../../custom/renderer/ModernMenuRenderer.hpp"
#include "../../../repositories/ProductRepositoryFactory.hpp"
#include "../../util/ShowProductPage.hpp"
#include "../AdvanceOptionShowPage.hpp"
#include <iostream>
#include <memory>

using Pages::Show::Sort::AscendingSortPage;

void AscendingSortPage::execute() {
  this->clearScreen();
  std::cout << "LIST PRODUK TERURUT SECARA ASCENDING\n";

  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  std::vector<Entity::Product *> products = productRepository->getAll();

  auto showProductPage = std::make_shared<Util::ShowProductPage>(products);
  this->renderPageDirectly(showProductPage);

  this->renderPageDirectly(std::make_shared<AdvanceOptionShowPage>());
}
