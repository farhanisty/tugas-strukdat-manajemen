#include "ShowPage.hpp"
#include "../../core/page/ExitPage.hpp"
#include "../../repositories/ProductRepositoryFactory.hpp"
#include "../util/PausePage.hpp"
#include "../util/ShowProductPage.hpp"
#include <iomanip>
#include <iostream>
#include <vector>

using Pages::Show::ShowPage, std::cout, Pages::Util::PausePage;

void ShowPage::configureMenu() {
  this->addMenu("Filter", this);
  this->addMenu("Sort", this);
  this->addMenu("Kembali", new Core::Page::ExitPage(this));
}

void ShowPage::before() {
  this->clearScreen();
  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  std::vector<Entity::Product *> products = productRepository->getAll();

  Util::ShowProductPage *showProductPage = new Util::ShowProductPage(products);
  this->renderPageDirectly(showProductPage);
}
