#pragma once

#include "Globals.h"

#include "WorldObject.h"

class Person :
	public WorldObject
{
public:
	Person(int age);
	virtual ~Person();

	int GetAge() const { return age; }

private:
	int age;
};

