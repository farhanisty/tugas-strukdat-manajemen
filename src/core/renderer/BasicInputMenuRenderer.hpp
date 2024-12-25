#ifndef Core_Renderer_BasicInputMenuRenderer_HPP
#define Core_Renderer_BasicInputMenuRenderer_HPP

#include "../input/Input.hpp"
#include "InputMenuRenderer.hpp"
#include <string>
#include <vector>

namespace Core::Renderer {
class BasicInputMenuRenderer : public InputMenuRenderer {
  std::string label;

public:
  BasicInputMenuRenderer();

  void changeLabel(std::string label);

  Input::Input *render(int totalPage) override;
};
} // namespace Core::Renderer

#endif
