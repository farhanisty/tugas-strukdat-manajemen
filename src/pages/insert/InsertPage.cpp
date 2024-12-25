#include "InsertPage.hpp"
#include "../../core/input/Input.hpp"
#include "../../core/input/InputBuilder.hpp"
#include "../../repositories/ProductRepositoryFactory.hpp"
#include "../../state/ProductState.hpp"
#include "../util/PausePage.hpp"
#include <iomanip>
#include <string>

using Pages::Insert::InsertPage, std::cout, std::setw, std::setfill,
    Core::Input::Input, Core::Input::InputBuilder;

void InsertPage::execute() {
  this->clearScreen();

  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  InputBuilder inputBuilder;

  cout << setw(1) << setfill('+') << "+";
  cout << setw(48) << setfill('=') << "";
  cout << setw(2) << setfill('+') << "+\n";
  cout << setw(1) << setfill('|') << "";
  cout << setw(19) << setfill(' ') << "";
  cout << "HELLO WORLD";
  cout << setw(18) << setfill(' ') << "";
  cout << setw(2) << setfill('|') << "|\n";
  cout << setw(1) << setfill('+') << "";
  cout << setw(48) << setfill('=') << "";
  cout << setw(2) << setfill('+') << "+\n";

  Input *inputCode = inputBuilder.setPrefix("\nInput code\t: ")->build();
  inputBuilder.fresh();
  Input *inputName = inputBuilder.setPrefix("Input name\t: ")->build();
  inputBuilder.fresh();
  Input *inputPrice = inputBuilder.setPrefix("Input price\t: ")->build();

  inputCode->execute();
  inputName->execute();
  inputPrice->execute();

  productRepository->insert(
      new Product({inputCode->getRawInput(), inputName->getRawInput(),
                   std::stof(inputPrice->getRawInput())}));

  cout << "\nProduk berhasil di tambah\n";

  this->renderPageDirectly(new Util::PausePage());
  delete inputCode;
}
