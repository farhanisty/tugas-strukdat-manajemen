#ifndef Core_Renderer_InputMenuRenderer_HPP
#define Core_Renderer_InputMenuRenderer_HPP

#include "../input/Input.hpp"
#include <vector>

namespace Core::Renderer {
class InputMenuRenderer {
public:
  virtual Input::Input *render(int totalPage) = 0;
  virtual ~InputMenuRenderer() {}
};
} // namespace Core::Renderer

#endif
