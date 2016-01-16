#pragma once

#include "Globals.h"

class Player;
class Team;

/// A Singleton class to hold the game state
class WorldDB
{
public:
	static void RegisterPlayer(sptr<Player> p);
	static void RegisterTeam(sptr<Team> t);

#ifdef _DEBUG
	static std::vector<sptr<Player>>* DEBUG_GetVectorOfPlayers() { return &allPlayers; }
	static std::vector<sptr<Team>>* DEBUG_GetVectorOfTeams(){ return &allTeams; }
#endif

private:
	static std::vector<sptr<Player>> allPlayers;
	static std::vector<sptr<Team>> allTeams;

};

