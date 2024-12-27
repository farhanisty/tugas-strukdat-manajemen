
#include "ProductRepositoryImpl.hpp"
#include <memory>
#include <vector>
using Repositories::ProductRepositoryImpl;

ProductRepositoryImpl::ProductRepositoryImpl() {
  this->productFileHandler =
      std::make_unique<File::ProductFileHandler>("data.csv");
  this->removedProductFileHandler =
      std::make_unique<File::ProductFileHandler>("remove.csv");

  this->products = this->productFileHandler->get();
}

bool ProductRepositoryImpl::insert(Entity::Product *product) {
  this->products.push_back(product);
  this->productFileHandler->create(product);
  return true;
}

std::vector<Entity::Product *> ProductRepositoryImpl::getAll() {
  return this->products;
}

Entity::Product *ProductRepositoryImpl::getByCode(string code) {
  Entity::Product *productFound = nullptr;

  for (auto product : this->getAll()) {
    if (product->code == code) {
      productFound = product;
      break;
    }
  }

  return productFound;
}
std::vector<Entity::Product *> ProductRepositoryImpl::getByName(string name) {
  return this->products;
}

std::vector<Entity::Product *>
ProductRepositoryImpl::getAllSortName(bool isAsc) {
  if (isAsc) {
    return this->products;
  }

  return this->products;
}

bool ProductRepositoryImpl::remove(string code) {
  Entity::Product *product = this->getByCode(code);

  if (product != nullptr) {
    int index = 0;

    int counter = 0;
    for (auto product : this->getAll()) {
      if (product->code == code) {
        break;
      }
      counter++;
    }

    this->removedProductFileHandler->create(product);
    this->productFileHandler->remove(code);

    this->products.erase(this->products.begin() + index);

    return true;
  } else {
    return false;
  }
}
