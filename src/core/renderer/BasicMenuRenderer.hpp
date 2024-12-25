#ifndef Core_Renderer_BasicMenuRenderer_HPP
#define Core_Renderer_BasicMenuRenderer_HPP

#include "../page//PageItem.hpp"
#include "MenuRenderer.hpp"
#include <vector>

namespace Core::Renderer {
class BasicMenuRenderer : public MenuRenderer {
public:
  void render(std::vector<Page::PageItem *> pageItems) override;
};
} // namespace Core::Renderer

#endif
