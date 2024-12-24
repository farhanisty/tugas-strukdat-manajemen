#include "InsertPage.hpp"
#include "../../core/page/ExitPage.hpp"
#include <iomanip>

using Pages::Insert::InsertPage, std::cout, std::setw, std::setfill;

void InsertPage::configureMenu() {
  this->addMenu("exit", new Core::Page::ExitPage(this));
}

void InsertPage::before() {
  this->clearScreen();
  cout << setw(1) << setfill('+') << "+";
  cout << setw(48) << setfill('=') << "";
  cout << setw(2) << setfill('+') << "+\n";
  cout << setw(1) << setfill('|') << "";
  cout << setw(19) << setfill(' ') << "";
  cout << "hello world";
  cout << setw(18) << setfill(' ') << "";
  cout << setw(2) << setfill('|') << "|\n";
  cout << setw(1) << setfill('+') << "";
  cout << setw(48) << setfill('=') << "";
  cout << setw(2) << setfill('+') << "+\n";
}
