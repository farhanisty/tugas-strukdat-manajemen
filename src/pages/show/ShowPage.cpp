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

  std::shared_ptr<Util::ShowProductPage> showProductPage =
      std::make_shared<Util::ShowProductPage>(products);
  this->renderPageDirectly(showProductPage);

  auto advanceOptionShowPage = std::make_shared<AdvanceOptionShowPage>();
  this->renderPageDirectly(advanceOptionShowPage);
}
