#ifndef Pages_History_PreOrderHistoryPage_HPP
#define Pages_History_PreOrderHistoryPage_HPP

#include "../../core/page/Page.hpp"

namespace Pages::History {
class PreOrderHistoryPage : public Core::Page::Page {
public:
  void execute() override;
};
} // namespace Pages::History

#endif
