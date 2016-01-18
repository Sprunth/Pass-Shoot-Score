#include "TimeManager.h"


TimeManager::TimeManager()
{
	WorldTime = { 0, 0, 0, 1, 0, 116, 0, 0, 0 };
}


TimeManager::~TimeManager()
{
}

void TimeManager::IncrementHour()
{
	WorldTime.tm_hour += 1;
	mktime(&WorldTime);
}

std::string TimeManager::GetWorldTimeStr(std::string format) const
{
	std::stringstream ss;
	ss << std::put_time(&WorldTime, format.c_str());
	return ss.str();
}

