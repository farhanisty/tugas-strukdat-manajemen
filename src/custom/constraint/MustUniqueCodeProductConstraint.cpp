#include "MustUniqueCodeProductConstraint.hpp"
#include "../../core/constraint/Constraint.hpp"
#include "../../core/constraint/ErrorBag.hpp"
#include "../../repositories/ProductRepositoryFactory.hpp"
#include <string>

using Custom::Constraint::MustUniqueCodeProductConstraint;

MustUniqueCodeProductConstraint::MustUniqueCodeProductConstraint() {
  this->setMessage("Code produk sudah digunakan");
}
bool MustUniqueCodeProductConstraint::check(
    std::string target, Core::Constraint::ErrorBag *errorBag) {

  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  if (productRepository->getByCode(target)) {
    errorBag->push(this->getMessage());
    return false;
  }

  return Core::Constraint::Constraint<std::string>::check(target, errorBag);
}
