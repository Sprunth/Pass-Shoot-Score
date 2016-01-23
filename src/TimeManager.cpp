#include "TimeManager.h"


TimeManager::TimeManager()
{
	tm startTime = { 0, 0, 0, 1, 0, 116, 0, 0, 0 };
	WorldTime = std::chrono::system_clock::from_time_t(mktime(&startTime));
}


TimeManager::~TimeManager()
{
}

void TimeManager::IncrementHour()
{
	WorldTime += std::chrono::hours(1);
}

std::string TimeManager::GetWorldTimeStr(std::string format) const
{
	std::stringstream ss;
	ss << std::put_time(&WorldTime, format.c_str());
	return ss.str();
}

