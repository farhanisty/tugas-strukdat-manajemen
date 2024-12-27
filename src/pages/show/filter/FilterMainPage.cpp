#include "FilterMainPage.hpp"
#include "../../../custom/renderer/ModernMenuRenderer.hpp"
#include "FilterCodePage.hpp"
#include <memory>

using Pages::Show::Filter::FilterMainPage;

void FilterMainPage::configureMenu() {
  auto modernMenuRenderer =
      std::make_shared<Custom::Renderer::ModernMenuRenderer>("OPSI FILTER");

  this->changeRenderer(modernMenuRenderer);
  this->addMenu("BERDASARKAN KODE", std::make_shared<FilterCodePage>());
  this->addMenu("BERDASARKAN NAMA", std::make_shared<FilterCodePage>());
}
