
#include "PausePage.hpp"
#include <iostream>
#include <string>

using Pages::Util::PausePage, std::cin, std::cout, std::string;

void PausePage::execute() {
  string tempInput;

  cout << "Input any key to continue...";

  cin >> tempInput;
}
