#include "MenuPage.hpp"
#include "../constraint/MustInRangeConstraint.hpp"
#include "../constraint/MustIntegerConstraint.hpp"
#include "../input/Input.hpp"
#include "../input/InputBuilder.hpp"
#include "iostream"
#include "string"

using Core::Input::InputBuilder, Core::Constraint::MustIntegerConstraint;

void Core::Page::MenuPage::addMenu(std::string label, Page *page) {
  this->pageItems.push_back(new PageItem(label, page));
}

void Core::Page::MenuPage::execute() {
  if (!this->isConfigured) {
    this->configureMenu();
    this->isConfigured = true;
  }

  this->before();

  int i = 1;

  for (auto pageItem : pageItems) {
    std::cout << i << ". " << pageItem->label << "\n";
    i++;
  }

  InputBuilder inputBuilder;
  inputBuilder.setPrefix("Masukkan input anda > ")
      ->setConstraint(new MustIntegerConstraint())
      ->setConstraint(
          new Constraint::MustInRangeConstraint(1, this->pageItems.size()));

  Input::Input *input = inputBuilder.build();

  input->execute();

  while (!input->isValid()) {
    std::cout << input->getErrorBag()->getErrors()[0] << "\n";
    input->execute();
  }

  int resultInput = stoi(input->getRawInput());

  this->pageItems[resultInput - 1]->page->execute();

  this->after();
}

std::string Core::Page::MenuPage::getInput() { return this->input; }

void Core::Page::MenuPage::after() {}

Core::Page::MenuPage::~MenuPage() {
  for (auto p : this->pageItems) {
    delete p;
  }
}
