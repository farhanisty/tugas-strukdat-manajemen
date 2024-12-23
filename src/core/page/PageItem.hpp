#ifndef Core_PageItem_HPP
#define Core_PageItem_HPP

#include "Page.hpp"
#include "string"

namespace Core::Page {

class PageItem {
public:
  std::string label;
  Page *page;
  PageItem(std::string label, Page *page) : label(label), page(page) {}
  virtual ~PageItem() { delete this->page; }
};
} // namespace Core::Page

#endif
