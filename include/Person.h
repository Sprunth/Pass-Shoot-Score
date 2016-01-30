#pragma once

#include "Globals.h"
#include "WorldDB.h"
#include "WorldObject.h"
#include "TimeHeader.h"

class Person :
	public WorldObject
{
public:
	Person(PSSDate birthday);
	virtual ~Person();

	int GetAge() const { return age; }

private:
	int age;
	PSSDate birthday;

	void OnBirthday(EventType);

	static int CalculateAge(const Person& p)
	{
		// todo

		auto birthday = p.birthday;

		auto worldDate = WorldDB::GetWorldTime().date();
		auto bDate = birthday.date();

		auto yrs = worldDate.year() - birthday.date().year();

		if	( ((worldDate.month() == bDate.month()) &&
			  (worldDate.day() < bDate.day())) ||
			  (worldDate.month() < bDate.month())
			)
		{
			yrs -= 1;
		}

		return yrs;
		
	}
};

