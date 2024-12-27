#include "PostOrderHistoryPage.hpp"
#include "../../repositories/ProductRepositoryFactory.hpp"
#include "../util/PausePage.hpp"
#include "../util/ShowProductPage.hpp"
#include <iostream>
#include <memory>

using Pages::History::PostOrderHistoryPage, std::cout;

void PostOrderHistoryPage::execute() {
  this->clearScreen();

  cout << "+----------------+-------------------------------+---------+\n";
  cout << "|                       POST ORDER HISTORY                 |\n";
  cout << "+----------------+-------------------------------+---------+\n";

  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  auto historyAvl = productRepository->getHistoryAvl();

  auto showProductPage =
      std::make_shared<Util::ShowProductPage>(historyAvl->getPostorder());
  this->renderPageDirectly(showProductPage);

  this->renderPageDirectly(std::make_shared<Util::PausePage>());
}
