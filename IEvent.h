#pragma once
#include "Macros.h"

enum EventType
{
    none = 0,
    windowClosed, windowResized, windowFocus, windowLostFocus, windowMoved,
    keyPressed, keyReleased,
    mouseButtonPressed, mouseButtonReleased, mouseMoved, mouseScrolled,
};

enum EventCategory
{
    knone        = 0,
    application = BIT(0),
    input       = BIT(1),
    keyboard    = BIT(2),
    mouse       = BIT(3),
    mouseButton = BIT(4),
};

class IEvent
{
public:
    virtual EventType getEventType() const = 0;
    virtual const char* getName() const = 0;
    virtual EventCategory getCategoryFlag() const = 0;
    virtual std::string ToString() const { return getName(); }

    virtual bool IsInCategory(EventCategory category)
    {
        return getCategoryFlag() & category;
    }

#define EVENT_CLASS_TYPE(type) static EventType getStaticEventType() { return EventType::##type; } \
                               virtual EventType getEventType() const override { return getStaticEventType(); } \
                               virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) int getCategoryFlag() { return category; }

protected :
    bool mHandled = false;
};

