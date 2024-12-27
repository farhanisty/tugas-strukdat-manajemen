#ifndef Custom_Renderer_ModernMenuRenderer_HPP
#define Custom_Renderer_ModernMenuRenderer_HPP

#include "../../core/page/PageItem.hpp"
#include "../../core/renderer/MenuRenderer.hpp"
#include <memory>
#include <string>
#include <vector>

namespace Custom::Renderer {
class ModernMenuRenderer : public Core::Renderer::MenuRenderer {
  std::string header;

  void fill(int size, std::string fill, std::string leftCorner = "",
            std::string rightCorner = "", bool endl = true);

  void centerizeString(int size, std::string param, std::string border = "",
                       bool endl = true);

  void createTwoCol(int size, int leftSize, std::string leftParam,
                    std::string rightParam, std::string border,
                    bool endl = true);

public:
  ModernMenuRenderer(std::string header);
  void
  render(std::vector<std::shared_ptr<Core::Page::PageItem>> pageItems) override;
};
} // namespace Custom::Renderer

#endif
