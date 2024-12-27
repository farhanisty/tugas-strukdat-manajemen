#ifndef Pages_Remove_RemovePage_HPP
#define Pages_Remove_RemovePage_HPP

#include "../../core/page/Page.hpp"

namespace Pages::Remove {
class RemovePage : public Core::Page::Page {
public:
  void execute() override;
};
} // namespace Pages::Remove

#endif
