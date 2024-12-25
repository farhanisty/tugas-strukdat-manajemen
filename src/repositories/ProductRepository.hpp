#ifndef Repositories_ProductRepository_HPP
#define Repositories_ProductRepository_HPP

#include "../entity/Product.hpp"
#include <vector>

namespace Repositories {
class ProductRepository {
public:
  virtual bool insert(Entity::Product *product) = 0;
  virtual std::vector<Entity::Product *> getAll() = 0;

  virtual ~ProductRepository() {}
};
} // namespace Repositories

#endif
