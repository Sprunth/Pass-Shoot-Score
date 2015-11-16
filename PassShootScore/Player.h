#pragma once

#include "Globals.h"

#include "WorldObject.h"

class Team;

class Player :
	public WorldObject
{
public:
	Player();
	~Player();

	int GetAge() const { return age; }

	sptr<Team> const GetTeam() { return team; }
	void SetTeam(sptr<Team> t) { team = t; }

private:
	
	int age;

	sptr<Team> team;
};

