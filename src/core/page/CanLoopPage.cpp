#include "CanLoopPage.hpp"

using Core::Page::CanLoopPage;

bool CanLoopPage::getIsStop() { return this->isStop; }
void CanLoopPage::setIsStop(bool isStop) { this->isStop = isStop; }
void CanLoopPage::setStop() { this->setIsStop(true); }
