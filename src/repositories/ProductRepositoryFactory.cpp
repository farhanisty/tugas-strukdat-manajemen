#include "ProductRepositoryFactory.hpp"
#include "ProductRepository.hpp"
#include "ProductRepositoryImpl.hpp"
#include <memory>
#include <mutex>

using Repositories::ProductRepositoryFactory;

std::shared_ptr<Repositories::ProductRepository>
    ProductRepositoryFactory::instance = nullptr;

std::mutex ProductRepositoryFactory::mutex;

std::shared_ptr<Repositories::ProductRepository>
ProductRepositoryFactory::getInstance() {
  std::lock_guard<std::mutex> lock(mutex);
  if (!instance) {
    instance = std::make_shared<ProductRepositoryImpl>();
  }

  return instance;
}
