
#include "ProductRepositoryImpl.hpp"
#include <memory>
#include <vector>
using Repositories::ProductRepositoryImpl;

ProductRepositoryImpl::ProductRepositoryImpl() {
  this->productFileHandler =
      std::make_unique<File::ProductFileHandler>("data.csv");
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
  return nullptr;
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
