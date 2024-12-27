#include "HistoryPage.hpp"
#include "../../custom/renderer/ModernMenuRenderer.hpp"
#include <memory>

using Pages::History::HistoryPage;

void HistoryPage::configureMenu() {
  this->changeRenderer(
      std::make_shared<Custom::Renderer::ModernMenuRenderer>("HISTORY"));
  this->addMenu("IN ORDER", std::make_shared<HistoryPage>());
  this->addMenu("POST ORDER", std::make_shared<HistoryPage>());
  this->addMenu("PRE ORDER", std::make_shared<HistoryPage>());
  this->addExit("Kembali");
}

void HistoryPage::before() { this->clearScreen(); }
