#include "ShowPage.hpp"
#include "../../core/page/ExitPage.hpp"
#include "../../repositories/ProductRepositoryFactory.hpp"
#include "../util/PausePage.hpp"
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

  // Tampilan tabel dengan bingkai Unicode
  cout << "╔" << std::string(48, '═') << "╗\n"; // Garis atas tabel
  cout << "║" << " \t\tDetail Produk" << std::setw(36) << std::setfill(' ')
       << " " << "║\n";                         // Header tabel
  cout << "╠" << std::string(48, '═') << "╣\n"; // Garis pemisah header

  for (auto product : products) {
    cout << "║ Code  : " << std::setw(35) << std::left
         << (product->code.empty() ? "-" : product->code) << " ║\n";
    cout << "║ Name  : " << std::setw(35) << std::left
         << (product->name.empty() ? "-" : product->name) << " ║\n";
    cout << "║ Price : " << std::setw(35) << std::left
         << (product->price == 0 ? "-" : std::to_string(product->price))
         << " ║\n";
    cout << "╠" << std::string(48, '═') << "╣\n"; // Garis pemisah antar produk
  }

  cout << "╚" << std::string(48, '═') << "╝\n"; // Garis bawah tabel
}
