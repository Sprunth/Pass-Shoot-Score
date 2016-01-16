#pragma once

#include "Globals.h"
#include "WorldObject.h"
#include "Player.h"
#include "WorldDB.h"

#include "GUI.h"

class Team : public WorldObject
{
public:
	Team();
	~Team();

	void AddPlayer(sptr<Player> p);
	void RemovePlayer(sptr<Player> p);

	void DrawTeamList();

private:
	std::vector<sptr<Player>> players;

};

