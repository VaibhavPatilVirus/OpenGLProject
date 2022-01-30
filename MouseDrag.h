#pragma once
#include "CursorPos.h"

class MouseDrag
{
public:
    bool mStarted;
    CursorPos mInitialPos;
    CursorPos mCurrentPos;
    
    MouseDrag(): mStarted(false), mInitialPos(CursorPos(0, 0)), mCurrentPos(CursorPos(0, 0)) {}
};

