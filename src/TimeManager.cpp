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
	auto ttime_t = std::chrono::system_clock::to_time_t(WorldTime);
#if defined(_MSC_VER)
	tm* ttm = new tm();
	gmtime_s(ttm, &ttime_t);
#else
	auto ttm = gmtime(&ttime_t);
#endif
	ss << std::put_time(ttm, format.c_str());

#if defined(_MSC_VER)
	free(ttm);
#endif

	return ss.str();
}

