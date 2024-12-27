#include "PreOrderHistoryPage.hpp"
#include "../../repositories/ProductRepositoryFactory.hpp"
#include "../util/PausePage.hpp"
#include "../util/ShowProductPage.hpp"
#include <iostream>
#include <memory>

using Pages::History::PreOrderHistoryPage, std::cout;

void PreOrderHistoryPage::execute() {
  this->clearScreen();

  cout << "+----------------+-------------------------------+---------+\n";
  cout << "|                       PRE ORDER HISTORY                   |\n";
  cout << "+----------------+-------------------------------+---------+\n";

  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  auto historyAvl = productRepository->getHistoryAvl();

  auto showProductPage =
      std::make_shared<Util::ShowProductPage>(historyAvl->getPreorder());
  this->renderPageDirectly(showProductPage);

  this->renderPageDirectly(std::make_shared<Util::PausePage>());
}
