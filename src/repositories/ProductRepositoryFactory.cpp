#include "ProductRepositoryFactory.hpp"
#include "ProductRepository.hpp"
#include "ProductRepositoryImpl.hpp"
#include <memory>

using Repositories::ProductRepositoryFactory;

std::shared_ptr<Repositories::ProductRepository>
    ProductRepositoryFactory::instance = nullptr;

std::shared_ptr<Repositories::ProductRepository>
ProductRepositoryFactory::getInstance() {
  if (!instance) {
    instance = std::make_shared<ProductRepositoryImpl>();
  }

  return instance;
}
