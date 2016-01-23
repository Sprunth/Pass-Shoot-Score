#pragma once

#include "Globals.h"
#include "GUI.h"
#include "TimeHeader.h"
#include <iomanip>

class TimeManager
{
public:
	TimeManager();
	~TimeManager();

	void IncrementHour();

	std::string GetWorldTimeStr(std::string format = "%b %d, %Y  %H-%M") const;

	TimePoint GetWorldTime() const { return WorldTime; }

private:
	TimePoint WorldTime;
};

