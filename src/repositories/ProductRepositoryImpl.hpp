#ifndef Repositories_ProductRepositoryImpl_HPP
#define Repositories_ProductRepositoryImpl_HPP

#include "ProductRepository.hpp"
namespace Repositories {
class ProductRepositoryImpl : public ProductRepository {
  std::vector<Entity::Product *> products;

public:
  bool insert(Entity::Product *) override;
  std::vector<Entity::Product *> getAll() override;
  Entity::Product *getByCode(string code) override;
  std::vector<Entity::Product *> getByName(string name) override;
};
} // namespace Repositories

#endif
