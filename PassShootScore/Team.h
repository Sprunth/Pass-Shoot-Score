#pragma once

#include "Globals.h"
#include "WorldObject.h"

#include "Player.h"


class Team :
	public WorldObject
{
public:
	Team();
	~Team();

	std::vector<sptr<Player>> GetPlayers() const { return players; }
	void AddPlayer(sptr<Player> player) 
	{ 
		players.push_back(player);
		player->SetTeam(std::static_pointer_cast<Team>(this->shared_from_this()));
	}

private:
	
	std::vector<sptr<Player>> players;
	
};

