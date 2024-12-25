#ifndef Repositories_ProductRepositoryFactory_HPP
#define Repositories_ProductRepositoryFactory_HPP

#include "../entity/Product.hpp"
#include "ProductRepository.hpp"
#include <memory>
#include <mutex>
#include <vector>

namespace Repositories {
class ProductRepositoryFactory {
  static std::shared_ptr<ProductRepository> instance;
  static std::mutex mutex;

  ProductRepositoryFactory() {}

public:
  ProductRepositoryFactory(const ProductRepositoryFactory &) = delete;

  ProductRepositoryFactory &
  operator=(const ProductRepositoryFactory &) = delete;

  static std::shared_ptr<ProductRepository> getInstance();
};
} // namespace Repositories

#endif
