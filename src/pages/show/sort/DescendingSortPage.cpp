#include "DescendingSortPage.hpp"
#include "../../../custom/renderer/ModernMenuRenderer.hpp"
#include "../../../repositories/ProductRepositoryFactory.hpp"
#include "../../util/ShowProductPage.hpp"
#include "../AdvanceOptionShowPage.hpp"
#include <iostream>
#include <memory>

using Pages::Show::Sort::DescendingSortPage;

void DescendingSortPage::execute() {
  this->clearScreen();
  std::cout << "LIST PRODUK TERURUT SECARA DESCENDING\n";

  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  std::vector<Entity::Product *> products =
      productRepository->getAllSortName(false);

  auto showProductPage = std::make_shared<Util::ShowProductPage>(products);
  this->renderPageDirectly(showProductPage);

  this->renderPageDirectly(std::make_shared<AdvanceOptionShowPage>());
}
