#pragma once

#include "Globals.h"

class WorldObject;
class Player;
class Team;

class WorldObjectFactory
{
public:
	static sptr<Player> CreatePlayer();
	static sptr<Team> CreateTeam();

private:

	static void RegisterWorldObject(sptr<WorldObject> obj);
};

