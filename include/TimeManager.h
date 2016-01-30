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

	std::string GetWorldTimeStr() const;

	PSSDate GetWorldTime() const { return WorldTime; }

private:
	PSSDate WorldTime;
};

