#ifndef Repositories_ProductRepositoryImpl_HPP
#define Repositories_ProductRepositoryImpl_HPP

#include "../file/ProductFileHandler.hpp"
#include "ProductRepository.hpp"
#include <memory>

namespace Repositories {
class ProductRepositoryImpl : public ProductRepository {
  std::vector<Entity::Product *> products;
  std::unique_ptr<File::ProductFileHandler> productFileHandler;

public:
  ProductRepositoryImpl();
  bool insert(Entity::Product *) override;
  std::vector<Entity::Product *> getAll() override;
  Entity::Product *getByCode(string code) override;
  std::vector<Entity::Product *> getByName(string name) override;
  std::vector<Entity::Product *> getAllSortName(bool isAsc = true) override;
};
} // namespace Repositories

#endif
