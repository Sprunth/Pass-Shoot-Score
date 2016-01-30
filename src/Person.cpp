#include "Person.h"


Person::Person(PSSDate birthday) : birthday(birthday)
{
	OnBirthday(EventType::PLAYER_BIRTHDAY);
	std::cout << "Birthday generated on: " << TimeHeader::FormatPosixTime(birthday) << std::endl;

}


Person::~Person()
{
}


void Person::OnBirthday(EventType)
{
	age = CalculateAge(*this);

	auto oneYr = boost::gregorian::years(1);
	auto nextBirthday = WorldDB::GetWorldTime() + oneYr;
	std::cout << "Current birthday: " << TimeHeader::FormatPosixTime(birthday) << std::endl;
	std::cout << "Next birthday: " << TimeHeader::FormatPosixTime(nextBirthday) << std::endl;
	std::cout << "Age: " << age << std::endl;

	std::function<void(EventType)> bday_callback = std::bind(&Person::OnBirthday, this, std::placeholders::_1);
	WorldDB::RegisterEvent(nextBirthday, bday_callback, EventType::PLAYER_BIRTHDAY);
}
