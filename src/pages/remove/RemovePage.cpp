
#include "RemovePage.hpp"
#include "../../core/input/Input.hpp"
#include "../../core/input/InputBuilder.hpp"
#include "../../repositories/ProductRepositoryFactory.hpp"
#include "../util/PausePage.hpp"
#include "../util/ShowProductPage.hpp"
#include <iostream>
#include <memory>

using Pages::Remove::RemovePage, Core::Input::Input, Core::Input::InputBuilder,
    std::cout;

void RemovePage::execute() {
  this->clearScreen();

  cout << "+----------------+-------------------------------+---------+\n";
  cout << "|                         HALAMAN HAPUS                    |\n";
  cout << "+----------------+-------------------------------+---------+\n";

  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  this->renderPageDirectly(
      std::make_shared<Util::ShowProductPage>(productRepository->getAll()));

  InputBuilder inputBuilder;
  Core::Input::Input *input =
      inputBuilder.setPrefix("Masukkan kode yang akan dihapus > ")->build();

  input->execute();

  Entity::Product *product = productRepository->getByCode(input->getRawInput());

  if (productRepository->remove(input->getRawInput())) {
    cout << "[SUKSES] Produk dengan kode " << input->getRawInput()
         << " berhasil dihapus\n";
  } else {
    cout << "[ERROR] Produk dengan kode " << input->getRawInput()
         << " tidak ditemukan\n";
  }

  this->renderPageDirectly(std::make_shared<Util::PausePage>());

  delete input;
}
