#ifndef Core_PageItem_HPP
#define Core_PageItem_HPP

#include "Page.hpp"
#include "string"
#include <memory>

namespace Core::Page {

class PageItem {
public:
  std::string label;
  std::shared_ptr<Page> page;
  PageItem(std::string label, std::shared_ptr<Page> page)
      : label(label), page(page) {}
};
} // namespace Core::Page

#endif
