#ifndef Pages_Util_ShowProductPage_HPP
#define Pages_Util_ShowProductPage_HPP

#include "../../core/page/Page.hpp"
#include "../../entity/Product.hpp"
#include <vector>

namespace Pages::Util {
class ShowProductPage : public Core::Page::Page {
  std::vector<Entity::Product*> products;
public:
  ShowProductPage(std::vector<Entity::Product *> products);
  void execute() override;
};
} // namespace Pages::Util

#endif
