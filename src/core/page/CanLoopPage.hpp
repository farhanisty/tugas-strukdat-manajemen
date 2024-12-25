#ifndef Core_Page_CanLoopPage_HPP
#define Core_Page_CanLoopPage_HPP

#include "Page.hpp"

namespace Core::Page {
class CanLoopPage : public Page {
  bool isStop = false;

public:
  bool getIsStop();
  void setIsStop(bool isStop);
  void setStop();

  virtual ~CanLoopPage() {}
};
} // namespace Core::Page

#endif
