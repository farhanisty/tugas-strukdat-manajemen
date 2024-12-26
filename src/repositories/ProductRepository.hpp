#ifndef Repositories_ProductRepository_HPP
#define Repositories_ProductRepository_HPP

#include "../entity/Product.hpp"
#include <vector>

namespace Repositories {
class ProductRepository {
public:
  virtual bool insert(Entity::Product *product) = 0;
  virtual std::vector<Entity::Product *> getAll() = 0;
  virtual Entity::Product *getByCode(string code) = 0;
  virtual std::vector<Entity::Product *> getByName(string name) = 0;
  virtual std::vector<Entity::Product *> getAllSortName(bool isAsc = true) = 0;

  virtual ~ProductRepository() {}
};
} // namespace Repositories

#endif
