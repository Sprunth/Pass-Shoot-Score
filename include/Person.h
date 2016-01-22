#pragma once

#include "Globals.h"
#include "WorldDB.h"
#include "WorldObject.h"

class Person :
	public WorldObject
{
public:
	Person(tm birthday);
	virtual ~Person();

	int GetAge() const { return age; }

private:
	int age;
	tm birthday;

	void OnBirthday(EventType);

	static int CalculateAge(const Person& p)
	{
		// todo
		return 0;
	}
};

