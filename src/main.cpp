#include "core/page/MenuPage.hpp"
#include "core/page/Page.hpp"
#include <iostream>

using namespace std;

class MainPage : public Core::Page::MenuPage {
public:
  void execute() override {
    cout << "Selamat Datang di Pusat pembelanjaan\n";

    // Menambahkan menu
    this->addMenu("Lihat Buku", this);

    // Menampilan opsi
    Core::Page::MenuPage::execute();
    cout << this->getInput();
  }
};

int main() {
  MainPage mainPage;

  mainPage.execute();
  return 0;
}
