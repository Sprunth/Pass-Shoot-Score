#include "Person.h"


Person::Person(int age) : age(age)
{
	birthday = WorldDB::GetWorldTime();
	birthday.tm_year -= age;
	birthday.tm_yday -= 364;
	mktime(&birthday);
	std::cout << "Birthday generated on: " << std::put_time(&birthday, "%b %d, %Y  %H-%M") << std::endl;
}


Person::~Person()
{
}
