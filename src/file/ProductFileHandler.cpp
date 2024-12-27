#include "ProductFileHandler.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using File::ProductFileHandler;
ProductFileHandler::ProductFileHandler(std::string filename)
    : filename(filename) {}

void ProductFileHandler::overwriteFile(const std::vector<Product *> products) {
  std::ofstream file(this->filename, std::ios::trunc); // Mode truncate
  if (file.is_open()) {
    for (const auto &product : products) {
      file << product->code << "," << product->name << "," << product->price
           << "\n";
    }
    file.close();
  } else {
    std::cerr << "Failed to open file.\n";
  }
}

bool ProductFileHandler::create(const Product *product) {
  std::ofstream file(this->filename, std::ios::app); // Mode append
  if (file.is_open()) {
    file << product->code << "," << product->name << "," << product->price
         << "\n";
    file.close();
    return true;
  } else {
    return false;
  }
  return true;
}

std::vector<Product *> ProductFileHandler::get() {
  std::vector<Product *> products;
  std::ifstream file(this->filename);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      std::istringstream iss(line);
      std::string code, name, priceStr;
      if (std::getline(iss, code, ',') && std::getline(iss, name, ',') &&
          std::getline(iss, priceStr)) {
        products.push_back(new Product({code, name, std::stof(priceStr)}));
      }
    }
    file.close();
  } else {
    std::cerr << "Failed to open file.\n";
  }
  return products;
}

// void ProductFileHandler::update(const std::string code,
//                                 Product *updatedProduct) {
//
//   std::vector<Product *> products = get();
//   bool found = false;
//
//   for (auto product : products) {
//     if (product->code == code) {
//       product = updatedProduct;
//       found = true;
//       break;
//     }
//   }
//
//   if (found) {
//     overwriteFile(products);
//     std::cout << "Product updated successfully.\n";
//   } else {
//     std::cerr << "Product not found.\n";
//   }
// }
//
// // Delete: Hapus produk berdasarkan kode
bool ProductFileHandler::remove(const std::string code) {
  std::vector<Product *> products = get();
  bool found = false;

  products.erase(std::remove_if(products.begin(), products.end(),
                                [&found, &code](const Product *product) {
                                  if (product->code == code) {
                                    found = true;
                                    return true;
                                  }
                                  return false;
                                }),
                 products.end());

  if (found) {
    overwriteFile(products);
    return true;
  } else {
    return false;
  }
}
