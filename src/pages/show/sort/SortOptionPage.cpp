#include "SortOptionPage.hpp"
#include "../../../custom/renderer/ModernMenuRenderer.hpp"
#include "AscendingSortPage.hpp"
#include "DescendingSortPage.hpp"

using Pages::Show::Sort::SortOptionPage;

void SortOptionPage::configureMenu() {
  this->changeRenderer(std::make_shared<Custom::Renderer::ModernMenuRenderer>(
      "OPSI PENGURUTAN"));

  this->addMenu("ASCENDING", std::make_shared<AscendingSortPage>());
  this->addMenu("DESCENDING", std::make_shared<DescendingSortPage>());
}
