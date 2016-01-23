#pragma once

#include "Globals.h"
#include "WorldDB.h"
#include "WorldObject.h"

class Person :
	public WorldObject
{
public:
	Person(TimePoint birthday);
	virtual ~Person();

	int GetAge() const { return age; }

private:
	int age;
	TimePoint birthday;

	void OnBirthday(EventType);

	static int CalculateAge(const Person& p)
	{
		// todo
		return 0;
	}
};

