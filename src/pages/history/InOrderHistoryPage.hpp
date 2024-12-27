#ifndef Pages_History_InOrderHistoryPage_HPP
#define Pages_History_InOrderHistoryPage_HPP

#include "../../core/page/Page.hpp"

namespace Pages::History {
class InOrderHistoryPage : public Core::Page::Page {
public:
  void execute() override;
};
} // namespace Pages::History

#endif
