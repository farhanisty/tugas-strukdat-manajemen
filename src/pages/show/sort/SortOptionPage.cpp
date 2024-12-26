#include "SortOptionPage.hpp"
#include "../../../custom/renderer/ModernMenuRenderer.hpp"
#include "AscendingSortPage.hpp"

using Pages::Show::Sort::SortOptionPage;

void SortOptionPage::configureMenu() {
  delete this->getRenderer();

  this->changeRenderer(
      new Custom::Renderer::ModernMenuRenderer("OPSI PENGURUTAN"));

  this->addMenu("ASCENDING", new AscendingSortPage());
  this->addMenu("DESCENDING", this);
}
