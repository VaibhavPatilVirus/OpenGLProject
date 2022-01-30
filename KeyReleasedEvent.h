#pragma once
#include "KeyEvent.h"
class KeyReleasedEvent :
    public KeyEvent
{
public:
    KeyReleasedEvent(const int& keyCode, const int& repeatCnt) : KeyEvent(keyCode), mRepeatCnt(repeatCnt) {}


    int mRepeatCnt;
};

