#include "ModernMenuRenderer.hpp"
#include <iomanip>
#include <iostream>
#include <locale>
#include <string>

using Custom::Renderer::ModernMenuRenderer, std::cout, std::cin, std::setw,
    std::setfill, std::endl;

void ModernMenuRenderer::fill(int size, std::string fill,
                              std::string leftCorner, std::string rightCorner,
                              bool endl) {
  if (leftCorner != "") {
    cout << leftCorner;
    size -= 2;
  }

  while (size) {
    cout << fill;
    size--;
  }

  if (rightCorner != "") {
    cout << rightCorner;
  }

  if (endl) {
    cout << "\n";
  }
}

ModernMenuRenderer::ModernMenuRenderer(std::string header) {
  this->header = header;
}

void ModernMenuRenderer::centerizeString(int size, std::string param,
                                         std::string border, bool endl) {
  if (border != "") {
    cout << border;
    size -= 2;
  }

  int leftSpaceWidth = (size / 2) - param.size() / 2;

  for (int i = 0; i < leftSpaceWidth; i++) {
    cout << " ";
  }

  cout << param;

  for (int i = 0; i < size - leftSpaceWidth - param.size(); i++) {
    cout << " ";
  }

  if (border != "") {
    cout << border;
  }

  if (endl) {
    cout << "\n";
  }
}

void ModernMenuRenderer::createTwoCol(int size, int leftSize,
                                      std::string leftParam,
                                      std::string rightParam,
                                      std::string border, bool endl) {
  cout << border << " ";
  cout << leftParam;

  int leftWidth = leftSize - leftParam.size() - 1;

  while (leftWidth) {
    cout << " ";
    leftWidth--;
  }

  size = size - 2 - leftSize;

  cout << border << " " << rightParam;
  int rightWidth = size - 2 - rightParam.size();

  while (rightWidth) {
    cout << " ";
    rightWidth--;
  }

  cout << border;

  if (endl) {
    cout << "\n";
  }
}

void ModernMenuRenderer::render(
    std::vector<std::shared_ptr<Core::Page::PageItem>> pageItems) {
  int size = 50;
  // cout << "╔═════════════════════════════════════╗" << endl;
  // cout << "║       MENU MANAJEMEN TOKO           ║" << endl;
  // cout << "╠═════╦══════════════════════════════╣" << endl;
  // cout << "║ No  ║ Pilihan Menu                 ║" << endl;
  // cout << "╠═════╬══════════════════════════════╣" << endl;
  // cout << "║ 1   ║ Input Produk 📦              ║" << endl;
  // cout << "║ 2   ║ Tampilkan Produk 📋          ║" << endl;
  // cout << "║ 3   ║ Hapus Produk 🗑️               ║" << endl;
  // cout << "║ 4   ║ Cari Produk by Kode 🔍       ║" << endl;
  // cout << "║ 5   ║ Cari Produk by Rentang Nama  ║" << endl;
  // cout << "║ 6   ║ Urutkan Produk (Descending)  ║" << endl;
  // cout << "║ 7   ║ Lihat Produk Dihapus 📜      ║" << endl;
  // cout << "║ 8   ║ Traversal Produk             ║" << endl;
  // cout << "║ 0   ║ Keluar Aplikasi 🚪           ║" << endl;
  // cout << "╚═════╩══════════════════════════════╝" << endl;
  this->fill(size, "═", "╔", "╗");
  this->centerizeString(size, this->header, "║");
  this->fill(size, "═", "╠", "╣");
  this->createTwoCol(size, 5, "No", "Pilihan Menu", "║");
  this->fill(size, "═", "╠", "╣");

  int count = 1;

  for (auto pageItem : pageItems) {
    this->createTwoCol(size, 5, std::to_string(count), pageItem->label, "║");
    count++;
  }

  // this->createTwoCol(size, 5, "1", "Input Produk 📦", "║");
  // this->createTwoCol(size, 5, "2", "Tampilkan Produk 📋", "║");
  // this->createTwoCol(size, 5, "3", "Hapus Produk 🗑️", "║");
  // this->createTwoCol(size, 5, "4", "Cari Produk by Kode 🔍", "║");
  // this->createTwoCol(size, 5, "5", "Cari Produk by Rentang Nama", "║");
  // this->createTwoCol(size, 5, "6", "Urutkan Produk (Descending)", "║");
  // this->createTwoCol(size, 5, "7", "Lihat Produk Dihapus 📜", "║");
  // this->createTwoCol(size, 5, "8", "Traversal Produk", "║");
  // this->createTwoCol(size, 5, "0", "Keluar Aplikasi 🚪", "║");

  this->fill(size, "═", "╚", "╝");
}
