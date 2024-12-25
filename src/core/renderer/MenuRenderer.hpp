#ifndef Core_Renderer_MenuRenderer_HPP
#define Core_Renderer_MenuRenderer_HPP

#include "../page//PageItem.hpp"
#include <vector>

namespace Core::Renderer {
class MenuRenderer {
public:
  virtual void render(std::vector<Page::PageItem *> pageItems) = 0;
  virtual ~MenuRenderer() {}
};
} // namespace Core::Renderer

#endif
