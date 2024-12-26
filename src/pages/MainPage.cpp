#include "MainPage.hpp"
#include "../core/page/ExitPage.hpp"
#include "../custom/renderer/ModernMenuRenderer.hpp"
#include "insert/InsertPage.hpp"
#include "show/ShowPage.hpp"

using Pages::MainPage;

void MainPage::configureMenu() {
  this->addMenu("Input Produk", new Pages::Insert::InsertPage());
  this->addMenu("Tampil Produk", new Show::ShowPage());
  this->addMenu("Hapus Produk", new Pages::Show::ShowPage());
  this->addMenu("History", new Pages::Show::ShowPage());
  this->addMenu("exit", new Core::Page::ExitPage(this));
}

void MainPage::before() { this->clearScreen(); }
