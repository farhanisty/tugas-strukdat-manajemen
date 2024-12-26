#include "FilterMainPage.hpp"
#include "../../../custom/renderer/ModernMenuRenderer.hpp"

using Pages::Show::Filter::FilterMainPage;

void FilterMainPage::configureMenu() {
  delete this->getRenderer();
  Custom::Renderer::ModernMenuRenderer *modernMenuRenderer =
      new Custom::Renderer::ModernMenuRenderer("OPSI FILTER");

  this->changeRenderer(modernMenuRenderer);
  this->addMenu("BERDASARKAN KODE", this);
  this->addMenu("BERDASARKAN NAMA", this);
}
