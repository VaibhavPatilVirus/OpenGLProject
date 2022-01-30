#pragma once
#include "MouseEvent.h"
class MouseButtonPressedEvent :
    public MouseButtonEvent
{
public:
    MouseButtonPressedEvent(const int& button)
        : MouseButtonEvent(button) {}

    EVENT_CLASS_TYPE(mouseButtonPressed)
};

