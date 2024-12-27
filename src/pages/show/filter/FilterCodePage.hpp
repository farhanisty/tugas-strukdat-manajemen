#ifndef Pages_Show_Filter_FilterCodePage_HPP
#define Pages_Show_Filter_FilterCodePage_HPP

#include "../../../core/page/Page.hpp"

namespace Pages::Show::Filter {
class FilterCodePage : public Core::Page::Page {
public:
  void execute() override;
};
} // namespace Pages::Show::Filter

#endif
