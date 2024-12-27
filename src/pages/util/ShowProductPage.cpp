#include "ShowProductPage.hpp"
#include <iomanip>
#include <iostream>

using Pages::Util::ShowProductPage, std::cout, std::endl, std::left, std::setw,
    std::setprecision, std::fixed;

ShowProductPage::ShowProductPage(std::vector<Entity::Product *> products)
    : products(products) {}

void ShowProductPage::execute() {
  if (this->products.size()) {
    cout << "+----------------+-------------------------------+---------+\n";
    cout << "| Code           | Name                          | Price   |\n";
    cout << "+----------------+-------------------------------+---------+\n";

    for (auto product : this->products) {
      cout << "| " << left << setw(15) << product->code << "| " << setw(30)
           << product->name << "| " << setw(8) << fixed << setprecision(2)
           << product->price << "|\n";
    }
    cout << "+----------------+-------------------------------+---------+\n";
  } else {
    cout << "+----------------+-------------------------------+---------+\n";
    cout << "|                      PRODUCT IS EMPTY                    |\n";
    cout << "+----------------+-------------------------------+---------+\n";
  }
}
