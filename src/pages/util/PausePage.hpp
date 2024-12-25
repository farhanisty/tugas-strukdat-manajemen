#ifndef Pages_PausePage_HPP
#define Pages_PausePage_HPP

#include "../../core/page/Page.hpp"

namespace Pages::Util {

class PausePage : public Core::Page::Page {
public:
  void execute() override;
};

} // namespace Pages::Util

#endif
