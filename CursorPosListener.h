#pragma once
#include "CursorPos.h"

class CursorPosListener
{
public:
	virtual ~CursorPosListener() {}

	virtual void callbackCursorPos(const CursorPos& cursorPos) = 0;
};

