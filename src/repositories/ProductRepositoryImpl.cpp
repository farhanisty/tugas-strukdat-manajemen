#include "ProductRepositoryImpl.hpp"
#include <algorithm>
#include <hash_map>
#include <iostream>
#include <memory>
#include <vector>

using Repositories::ProductRepositoryImpl;

ProductRepositoryImpl::ProductRepositoryImpl() {
  this->productFileHandler =
      std::make_unique<File::ProductFileHandler>("data.csv");
  this->removedProductFileHandler =
      std::make_unique<File::ProductFileHandler>("remove.csv");

  this->historyAvl = std::make_unique<Avl::Avl>();
  this->productAvl = std::make_unique<Avl::Avl>();

  this->products = this->productFileHandler->get();

  // Inisalisasi data hash collection
  for (auto product : this->products) {
    this->hashCollection[product->code] =
        new Product({product->code, product->name, product->price});

    this->productAvl->insert(
        Product({product->code, product->name, product->price}));
  }

  for (auto product : this->removedProductFileHandler->get()) {
    this->historyAvl->insert(
        Product({product->code, product->name, product->price}));
  }
}

bool ProductRepositoryImpl::insert(Entity::Product *product) {
  // Insert data ke hash collection
  this->hashCollection[product->code] =
      new Product({product->code, product->name, product->price});
  this->productAvl->insert(
      Product({product->code, product->name, product->price}));
  this->products.push_back(product);

  this->productFileHandler->create(product);
  return true;
}

std::vector<Entity::Product *> ProductRepositoryImpl::getAll() {
  std::vector<Entity::Product *> inProducts;

  for (auto pair : this->hashCollection) {
    inProducts.push_back(pair.second);
  }

  return inProducts;
}

Entity::Product *ProductRepositoryImpl::getByCode(string code) {
  // Mengakses data dengan hash
  return this->hashCollection[code];
}
std::vector<Entity::Product *> ProductRepositoryImpl::getByName(string name) {
  return this->productAvl->searchRangeName(name);
}

std::vector<Entity::Product *>
ProductRepositoryImpl::getAllSortName(bool isAsc) {
  auto products = this->productAvl->getInorder();
  if (!isAsc) {
    std::reverse(products.begin(), products.end());
  }

  return products;
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

    this->hashCollection.erase(code);
    this->productAvl->deleteNode(product->name);
    this->historyAvl->insert(
        Product({product->code, product->name, product->price}));

    this->removedProductFileHandler->create(product);
    this->productFileHandler->remove(code);

    this->products.erase(this->products.begin() + index);

    return true;
  } else {
    return false;
  }
}

std::shared_ptr<Avl::Avl> ProductRepositoryImpl::getHistoryAvl() {
  return this->historyAvl;
}
