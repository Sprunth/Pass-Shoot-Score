#pragma once

#include "Globals.h"

#include "WorldObject.h"

class Team;

class Player :
	public WorldObject
{
public:
	friend class Team;

	Player();
	~Player();

	int GetAge() const { return age; }

	sptr<Team> const GetTeam() { return team; }
	

private:
	
	int age;

	void SetTeam(sptr<Team> t) { team = t; }
	sptr<Team> team;
};

