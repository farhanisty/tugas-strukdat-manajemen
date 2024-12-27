#ifndef Pages_Show_Sort_DescendingSortPage_HPP
#define Pages_Show_Sort_DescendingSortPage_HPP

#include "../../../core/page/Page.hpp"

namespace Pages::Show::Sort {
class DescendingSortPage : public Core::Page::Page {
public:
  void execute() override;
};
} // namespace Pages::Show::Sort

#endif
