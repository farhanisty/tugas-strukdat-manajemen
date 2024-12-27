#include "HistoryPage.hpp"
#include "../../custom/renderer/ModernMenuRenderer.hpp"
#include "InOrderHistoryPage.hpp"
#include "PostOrderHistoryPage.hpp"
#include "PreOrderHistoryPage.hpp"
#include <memory>

using Pages::History::HistoryPage;

void HistoryPage::configureMenu() {
  this->changeRenderer(
      std::make_shared<Custom::Renderer::ModernMenuRenderer>("HISTORY"));
  this->addMenu("IN ORDER", std::make_shared<InOrderHistoryPage>());
  this->addMenu("POST ORDER", std::make_shared<PostOrderHistoryPage>());
  this->addMenu("PRE ORDER", std::make_shared<PreOrderHistoryPage>());
  this->addExit("Kembali");
}

void HistoryPage::before() { this->clearScreen(); }
