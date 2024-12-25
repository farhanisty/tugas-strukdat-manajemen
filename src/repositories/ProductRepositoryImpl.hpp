#ifndef Repositories_ProductRepositoryImpl_HPP
#define Repositories_ProductRepositoryImpl_HPP

#include "ProductRepository.hpp"
namespace Repositories {
class ProductRepositoryImpl : public ProductRepository {
  std::vector<Entity::Product *> products;

public:
  bool insert(Entity::Product *) override;
  std::vector<Entity::Product *> getAll() override;
};
} // namespace Repositories

#endif
