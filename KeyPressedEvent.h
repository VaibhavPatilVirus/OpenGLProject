#pragma once
#include "KeyEvent.h"
class KeyPressedEvent :
    public KeyEvent
{
public:
    KeyPressedEvent(const int& keyCode): KeyEvent(keyCode){}

    EVENT_CLASS_TYPE(keyReleased)
};

