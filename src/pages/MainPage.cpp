#include "MainPage.hpp"
#include "../core/page/ExitPage.hpp"
#include "insert/InsertPage.hpp"
#include "show/ShowPage.hpp"

using Pages::MainPage;

void MainPage::configureMenu() {
  this->addMenu("insert", new Pages::Insert::InsertPage());
  this->addMenu("tampilkan", new Pages::Show::ShowPage());
  this->addMenu("exit", new Core::Page::ExitPage(this));
}

void MainPage::before() {
  this->clearScreen();
  std::cout << "hello world\n";
}
