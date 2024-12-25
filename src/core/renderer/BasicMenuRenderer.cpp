
#include "BasicMenuRenderer.hpp"
#include <vector>

using Core::Renderer::BasicMenuRenderer;

void BasicMenuRenderer::render(std::vector<Page::PageItem *> pageItems) {
  int i = 1;

  for (auto pageItem : pageItems) {
    std::cout << i << ". " << pageItem->label << "\n";
    i++;
  }
}