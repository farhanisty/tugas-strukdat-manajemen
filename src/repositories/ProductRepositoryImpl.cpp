
#include "ProductRepositoryImpl.hpp"
#include <vector>
using Repositories::ProductRepositoryImpl;

bool ProductRepositoryImpl::insert(Entity::Product *product) {
  this->products.push_back(product);
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
