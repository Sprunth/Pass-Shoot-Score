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

protected:
	void virtual InitSkills() = 0;
	void AddSkill(std::string s, float initVal = 0);
	void AddSkill(std::vector<std::string> s);
	float GetSkill(std::string s);
	void ChangeSkillValue(std::string s, float change);

private:
	int age;
	PSSDate birthday;
	
	std::map<std::string, float> skills;

	// birthday callback
	void OnBirthday(EventType);

	static int CalculateAge(const Person& p)
	{
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

