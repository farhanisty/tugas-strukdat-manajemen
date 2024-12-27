#ifndef Pages_History_PostOrderHistoryPage_HPP
#define Pages_History_PostOrderHistoryPage_HPP

#include "../../core/page/Page.hpp"

namespace Pages::History {
class PostOrderHistoryPage : public Core::Page::Page {
public:
  void execute() override;
};
} // namespace Pages::History

#endif
