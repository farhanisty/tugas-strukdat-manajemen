#ifndef Pages_InsertPage_HPP
#define Pages_InsertPage_HPP

#include "../../core/page/Page.hpp"

namespace Pages::Insert {

class InsertPage : public Core::Page::Page {
public:
  void execute() override;
};

} // namespace Pages::Insert

#endif
