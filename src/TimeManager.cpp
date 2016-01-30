#include "TimeManager.h"

TimeManager::TimeManager()
{
	std::string start_date = "2016-08-01 00:00:00";
	WorldTime = PSSDate(boost::posix_time::time_from_string(start_date));
}


TimeManager::~TimeManager()
{
}

void TimeManager::IncrementHour()
{
	auto hrs = boost::posix_time::hours(1);
	WorldTime += hrs;
}

std::string TimeManager::GetWorldTimeStr() const
{
	return to_simple_string(WorldTime);
}

