#include "ShowProductPage.hpp"
#include <iostream>
#include <iomanip>

using Pages::Util::ShowProductPage, std::cout, std::endl, std::left, std::setw, std::setprecision, std::fixed;

ShowProductPage::ShowProductPage(std::vector<Entity::Product*> products): products(products) {}

void ShowProductPage::execute(){

        cout << "+----------------+-------------------------------+---------+\n";
        cout << "| Code           | Name                          | Price   |\n";
        cout << "+----------------+-------------------------------+---------+\n";


            for(auto product: this->products) {
            cout << "| " << left << setw(15) << product->code 
                 << "| " << setw(30) << product->name 
                 << "| " << setw(8) << fixed << setprecision(2) << product->price << "|\n";
        }
        cout << "+----------------+-------------------------------+---------+\n";
    }
