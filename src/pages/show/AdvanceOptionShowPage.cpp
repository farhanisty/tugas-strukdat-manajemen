#include "AdvanceOptionShowPage.hpp"
#include "../../core/page/ExitPage.hpp"
#include "ShowPage.hpp"
#include "filter/FilterMainPage.hpp"
#include "sort/SortOptionPage.hpp"

using Pages::Show::AdvanceOptionShowPage;

void AdvanceOptionShowPage::configureMenu() {
  this->addMenu("Filter", new Filter::FilterMainPage());
  this->addMenu("Sort", new Sort::SortOptionPage());
  this->addMenu("Kembali", new Core::Page::ExitPage(this));
}
