#ifndef Repositories_ProductRepositoryImpl_HPP
#define Repositories_ProductRepositoryImpl_HPP

#include "../avl/Avl.hpp"
#include "../file/ProductFileHandler.hpp"
#include "ProductRepository.hpp"
#include <memory>
#include <unordered_map>

namespace Repositories {
class ProductRepositoryImpl : public ProductRepository {
  std::unordered_map<std::string, Entity::Product *> hashCollection;
  std::shared_ptr<Avl::Avl> historyAvl;
  std::shared_ptr<Avl::Avl> productAvl;
  std::vector<Entity::Product *> products;
  std::unique_ptr<File::ProductFileHandler> productFileHandler;
  std::unique_ptr<File::ProductFileHandler> removedProductFileHandler;

public:
  ProductRepositoryImpl();
  bool insert(Entity::Product *) override;
  std::vector<Entity::Product *> getAll() override;
  Entity::Product *getByCode(string code) override;
  std::vector<Entity::Product *> getByName(string name) override;
  std::vector<Entity::Product *> getAllSortName(bool isAsc = true) override;
  std::shared_ptr<Avl::Avl> getHistoryAvl() override;
  bool remove(string code) override;
};
} // namespace Repositories

#endif
