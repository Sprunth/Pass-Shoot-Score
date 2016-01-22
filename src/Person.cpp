#include "Person.h"


Person::Person(tm birthday) : birthday(birthday)
{
	age = CalculateAge(*this);
	std::cout << "Birthday generated on: " << std::put_time(&birthday, "%b %d, %Y  %H:%M") << std::endl;
	auto nextBirthday = birthday;
	//nextBirthday.tm_year++;
	nextBirthday.tm_mday += 3;
	nextBirthday.tm_year = WorldDB::GetWorldTime().tm_year;
	mktime(&nextBirthday);
	std::cout << "Next birthday:" << std::put_time(&nextBirthday, "%Y-%m-%d") << std::endl;

	std::function<void(EventType)> bday_callback = std::bind(&Person::OnBirthday, this, std::placeholders::_1);
	WorldDB::RegisterEvent(nextBirthday, bday_callback, EventType::PLAYER_BIRTHDAY);

}


Person::~Person()
{
}


void Person::OnBirthday(EventType)
{
	birthday.tm_mday++;
	mktime(&birthday);
	age = CalculateAge(*this);
}
