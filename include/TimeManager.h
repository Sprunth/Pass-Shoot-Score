#pragma once

#include "Globals.h"
#include "GUI.h"
#include <iomanip>

class TimeManager
{
public:
	TimeManager();
	~TimeManager();

	void IncrementHour();

	std::string GetWorldTimeStr(std::string format = "%b %d, %Y  %H-%M") const;

private:
	tm WorldTime;
};

