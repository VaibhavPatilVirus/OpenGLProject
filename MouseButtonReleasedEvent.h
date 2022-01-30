#pragma once
#include "MouseEvent.h"
#include <sstream>

class MouseButtonReleasedEvent :
    public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent(const int& button)
		: MouseButtonEvent(button) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << mButton;
		return ss.str();
	}

	EVENT_CLASS_TYPE(mouseButtonReleased)
};

