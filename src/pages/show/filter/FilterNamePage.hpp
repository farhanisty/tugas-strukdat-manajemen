#ifndef Pages_Show_Filter_FilterNamePage_HPP
#define Pages_Show_Filter_FilterNamePage_HPP

#include "../../../core/page/Page.hpp"

namespace Pages::Show::Filter {
class FilterNamePage : public Core::Page::Page {
public:
  void execute() override;
};
} // namespace Pages::Show::Filter

#endif
