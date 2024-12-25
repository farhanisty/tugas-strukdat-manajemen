#include "ShowPage.hpp"
#include "../../core/page/ExitPage.hpp"
#include "../../repositories/ProductRepositoryFactory.hpp"
#include "../util/PausePage.hpp"
#include <iostream>
#include <vector>

using Pages::Show::ShowPage, std::cout, Pages::Util::PausePage;

void ShowPage::configureMenu() {
  this->addMenu("Tampilkan semuanya", this);
  this->addMenu("Tampilkan sebagian", this);
  this->addMenu("Kembali", new Core::Page::ExitPage(this));
}

void ShowPage::before() {
  this->clearScreen();
  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  std::vector<Entity::Product *> products = productRepository->getAll();

  for (auto product : products) {
    cout << "code: " << product->code << "\n";
    cout << "name: " << product->name << "\n";
    cout << "price: " << product->price << "\n";
    cout << "------------------\n";
  }

  cout << "Menu Tampil\n";
}
