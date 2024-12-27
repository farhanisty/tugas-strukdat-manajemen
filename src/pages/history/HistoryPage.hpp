#ifndef Pages_History_HistoryPage_HPP
#define Pages_History_HistoryPage_HPP

#include "../../core/page/MenuPage.hpp"

namespace Pages::History {
class HistoryPage : public Core::Page::MenuPage {
public:
  void configureMenu() override;
};
} // namespace Pages::History

#endif
