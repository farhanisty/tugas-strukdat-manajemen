#include "MainPage.hpp"
#include "../core/page/ExitPage.hpp"
#include "../custom/renderer/ModernMenuRenderer.hpp"
#include "history/HistoryPage.hpp"
#include "insert/InsertPage.hpp"
// #include "insert/InsertPage.hpp"
#include "remove/RemovePage.hpp"
#include "show/ShowPage.hpp"
#include <memory>

using Pages::MainPage;

void MainPage::configureMenu() {
  this->addMenu("Input Produk", std::make_shared<Insert::InsertPage>());
  this->addMenu("Tampil Produk", std::make_shared<Show::ShowPage>());
  this->addMenu("Hapus Produk", std::make_shared<Remove::RemovePage>());
  this->addMenu("History", std::make_shared<History::HistoryPage>());
  this->addExit("exit");
}

void MainPage::before() { this->clearScreen(); }
