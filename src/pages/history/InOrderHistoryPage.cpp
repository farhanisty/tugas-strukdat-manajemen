#include "InOrderHistoryPage.hpp"
#include "../../repositories/ProductRepositoryFactory.hpp"
#include "../util/PausePage.hpp"
#include "../util/ShowProductPage.hpp"
#include <iostream>
#include <memory>

using Pages::History::InOrderHistoryPage, std::cout;

void InOrderHistoryPage::execute() {
  this->clearScreen();

  cout << "+----------------+-------------------------------+---------+\n";
  cout << "|                       IN ORDER HISTORY                   |\n";
  cout << "+----------------+-------------------------------+---------+\n";

  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  auto historyAvl = productRepository->getHistoryAvl();

  auto showProductPage =
      std::make_shared<Util::ShowProductPage>(historyAvl->getInorder());
  this->renderPageDirectly(showProductPage);

  this->renderPageDirectly(std::make_shared<Util::PausePage>());
}
