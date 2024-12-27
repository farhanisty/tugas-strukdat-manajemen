#include "FilterCodePage.hpp"
#include "../../../core/input/Input.hpp"
#include "../../../core/input/InputBuilder.hpp"
#include "../../../repositories/ProductRepositoryFactory.hpp"
#include "../../util/ShowProductPage.hpp"
#include "../AdvanceOptionShowPage.hpp"
#include <iostream>
#include <vector>

using Pages::Show::Filter::FilterCodePage, Core::Input::InputBuilder, std::cout;

void FilterCodePage::execute() {
  InputBuilder inputBuilder;
  Core::Input::Input *input =
      inputBuilder.setPrefix("Masukkan kode yang ingin dicari > ")->build();

  input->execute();

  this->clearScreen();

  cout << "+----------------+-------------------------------+---------+\n";
  cout << "|                       FILTER CODE PAGE                   |\n";
  cout << "+----------------+-------------------------------+---------+\n";

  auto productRepository =
      Repositories::ProductRepositoryFactory::getInstance();

  Entity::Product *product = productRepository->getByCode(input->getRawInput());

  std::vector<Entity::Product *> products;

  if (product != nullptr) {
    products.push_back(product);
  }

  this->renderPageDirectly(std::make_shared<Util::ShowProductPage>(products));

  this->renderPageDirectly(std::make_shared<AdvanceOptionShowPage>());
  delete input;
}
