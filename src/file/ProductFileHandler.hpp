#ifndef File_ProductFileHandler_HPP
#define File_ProductFileHandler_HPP

#include "../entity/Product.hpp"
#include <string>
#include <vector>

using Entity::Product;

namespace File {
class ProductFileHandler {
  std::string filename;
  void overwriteFile(const std::vector<Product *> products);

public:
  ProductFileHandler(std::string filename);

  bool create(const Product *product);

  std::vector<Product *> get();

  // void update(const std::string code, Product *updatedProduct);
  //
  bool remove(const std::string code);
};
} // namespace File

#endif
