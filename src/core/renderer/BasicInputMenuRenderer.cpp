#include "BasicInputMenuRenderer.hpp"
#include "../constraint/MustInRangeConstraint.hpp"
#include "../constraint/MustIntegerConstraint.hpp"
#include "../input/InputBuilder.hpp"

using Core::Renderer::BasicInputMenuRenderer, Core::Input::InputBuilder,
    Core::Constraint::MustIntegerConstraint,
    Core::Constraint::MustIntegerConstraint;

BasicInputMenuRenderer::BasicInputMenuRenderer() {
  this->label = "Masukkan input > ";
}

void BasicInputMenuRenderer::changeLabel(string label) { this->label = label; }

Core::Input::Input *BasicInputMenuRenderer::render(int totalPage) {
  InputBuilder inputBuilder;
  inputBuilder.setPrefix("Masukkan input anda > ")
      ->setConstraint(new MustIntegerConstraint())
      ->setConstraint(new Constraint::MustInRangeConstraint(1, totalPage));

  Input::Input *input = inputBuilder.build();

  input->execute();

  while (!input->isValid()) {
    std::cout << input->getErrorBag()->getErrors()[0] << "\n";
    input->execute();
  }

  return input;
}
