#include "MainPage.hpp"
#include "../core/page/ExitPage.hpp"
#include "../custom/renderer/ModernMenuRenderer.hpp"
#include "insert/InsertPage.hpp"
#include "show/ShowPage.hpp"

using Pages::MainPage;

void MainPage::configureMenu() {
  Pages::Show::ShowPage *showPage = new Show::ShowPage();
  auto tempRenderer = showPage->getRenderer();

  showPage->changeRenderer(
      new Custom::Renderer::ModernMenuRenderer("OPSI LANJUT"));

  this->addMenu("Input Produk", new Pages::Insert::InsertPage());
  this->addMenu("Tampil Produk", showPage);
  this->addMenu("Hapus Produk", new Pages::Show::ShowPage());
  this->addMenu("History", new Pages::Show::ShowPage());
  this->addMenu("exit", new Core::Page::ExitPage(this));
}

void MainPage::before() { this->clearScreen(); }
