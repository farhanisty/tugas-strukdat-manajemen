#include "InsertPage.hpp"
#include "../../core/input/Input.hpp"
#include "../../core/input/InputBuilder.hpp"
#include "../../custom/constraint/MustNumericConstraint.hpp"
#include "../../entity/Product.hpp"
#include "../../repositories/ProductRepositoryFactory.hpp"
#include "../util/PausePage.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using Pages::Insert::InsertPage, std::cout, std::endl, std::setw, std::setfill,
    Core::Input::Input, Core::Input::InputBuilder, Entity::Product,
    Custom::Constraint::MustNumericConstraint;

void InsertPage::execute() {
  this->clearScreen();

  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();
  InputBuilder inputBuilder;

  cout << "╔════════════════════════════════════╗" << endl;
  cout << "║                                    ║" << endl;
  cout << "║            INPUT PRODUK            ║" << endl;
  cout << "║                                    ║" << endl;
  cout << "╚════════════════════════════════════╝" << endl;

  Input *inputCode = inputBuilder.setPrefix("\nInput Code Produk\t: ")->build();
  inputBuilder.fresh();
  Input *inputName = inputBuilder.setPrefix("Input Nama Produk\t: ")->build();
  inputBuilder.fresh();
  Input *inputPrice = inputBuilder.setPrefix("Input Harga Produk\t: ")
                          ->setConstraint(new MustNumericConstraint())
                          ->build();

  inputCode->execute();
  inputName->execute(true);

  inputPrice->execute();

  while (!inputPrice->isValid()) {
    cout << inputPrice->getErrorBag()->getErrors()[0] << "\n";
    inputPrice->execute();
  }

  float price = std::stof(inputPrice->getRawInput());

  productRepository->insert(
      new Product({inputCode->getRawInput(), inputName->getRawInput(), price}));

  cout << "\n[SUKSES] Produk berhasil ditambahkan\n";

  this->renderPageDirectly(std::make_shared<Util::PausePage>());
  delete inputCode;
  delete inputName;
  delete inputPrice;
}
