#pragma once
#include "IEvent.h"
class MouseButtonEvent :
    public IEvent
{
public:
    int mButton; 
    int mAction;
    MouseButtonEvent(const int& button) : mButton(button){};
    
    EVENT_CLASS_CATEGORY(EventCategory::mouse | EventCategory::input | EventCategory::mouseButton)
};

