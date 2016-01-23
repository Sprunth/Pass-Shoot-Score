#include "Person.h"


Person::Person(TimePoint birthday) : birthday(birthday)
{
	OnBirthday(EventType::PLAYER_BIRTHDAY);
	std::cout << "Birthday generated on: " << std::put_time(birthday, "%b %d, %Y  %H:%M") << std::endl;

}


Person::~Person()
{
}


void Person::OnBirthday(EventType)
{
	age = CalculateAge(*this);

	auto tt = std::chrono::system_clock::to_time_t(birthday);
	auto ttm = gmtime(&tt);
	

	std::function<void(EventType)> bday_callback = std::bind(&Person::OnBirthday, this, std::placeholders::_1);
	WorldDB::RegisterEvent(nextBirthday, bday_callback, EventType::PLAYER_BIRTHDAY);
}
