#include "AdvanceOptionShowPage.hpp"
#include "../../custom/renderer/ModernMenuRenderer.hpp"
#include "ShowPage.hpp"
#include "filter/FilterMainPage.hpp"
#include "sort/SortOptionPage.hpp"
// #include "filter/FilterMainPage.hpp"

using Pages::Show::AdvanceOptionShowPage;

void AdvanceOptionShowPage::configureMenu() {
  this->changeRenderer(
      std::make_shared<Custom::Renderer::ModernMenuRenderer>("OPSI LANJUTAN"));
  this->addMenu("Filter", std::make_shared<Filter::FilterMainPage>());
  this->addMenu("Sort", std::make_shared<Sort::SortOptionPage>());
  this->addExit("Kembali");
}
