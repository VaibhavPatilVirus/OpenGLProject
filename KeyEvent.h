#pragma once
#include "IEvent.h"
class KeyEvent :
    public IEvent
{
    EVENT_CLASS_CATEGORY(EventCategory::keyboard | EventCategory::input)

protected:
    KeyEvent(const int& keyCode): mKeyCode(keyCode){}

    int mKeyCode;
};

