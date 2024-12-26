#ifndef Pages_Show_Sort_AscendingSortPage_HPP
#define Pages_Show_Sort_AscendingSortPage_HPP

#include "../../../core/page/Page.hpp"

namespace Pages::Show::Sort {
class AscendingSortPage : public Core::Page::Page {
public:
  void execute() override;
};
} // namespace Pages::Show::Sort

#endif
