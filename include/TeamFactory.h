#pragma once

#include "WorldObjectFactory.h"
#include "Team.h"
#include "WorldDB.h"

class TeamFactory :
	public WorldObjectFactory
{
public:
	TeamFactory();
	~TeamFactory();

	static sptr<Team> CreateTeam();

private:
	static TeamFactory* activeFactory;
};

