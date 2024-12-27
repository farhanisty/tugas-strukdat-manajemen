#include "FilterNamePage.hpp"
#include "../../../core/input/Input.hpp"
#include "../../../core/input/InputBuilder.hpp"
#include "../../../repositories/ProductRepositoryFactory.hpp"
#include "../../util/ShowProductPage.hpp"
#include "../AdvanceOptionShowPage.hpp"
#include <iostream>

using Pages::Show::Filter::FilterNamePage, Core::Input::InputBuilder, std::cout;

void FilterNamePage::execute() {
  InputBuilder inputBuilder;
  Core::Input::Input *input =
      inputBuilder.setPrefix("Masukkan rentang nama > ")->build();

  input->execute(true);

  this->clearScreen();

  cout << "+----------------+-------------------------------+---------+\n";
  cout << "|                       FILTER NAME PAGE                   |\n";
  cout << "+----------------+-------------------------------+---------+\n";

  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  auto products = productRepository->getByName(input->getRawInput());

  this->renderPageDirectly(std::make_shared<Util::ShowProductPage>(products));

  this->renderPageDirectly(std::make_shared<AdvanceOptionShowPage>());
  delete input;
}
