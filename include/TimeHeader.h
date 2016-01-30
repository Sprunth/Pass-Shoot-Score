#pragma once

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using PSSDate = boost::posix_time::ptime;

class TimeHeader
{
public:
	
	static std::string FormatPosixTime(const PSSDate d)
	{
		return boost::posix_time::to_simple_string(d);
	};

};
