#pragma once

#include "Globals.h"
#include <ctime>
#include <iomanip>

class Player;
class Team;

/// A Singleton class to hold the game state
class WorldDB
{
public:
	/// Creates a new world (game)
	static void NewWorld();
	static void LoadWorld();

	/// Simulate the world
	/// Returns true when time needs to stop for a decision
	static void Simulate(bool &stop);

	static void RegisterPlayer(sptr<Player> p);
	static void RegisterTeam(sptr<Team> t);

#ifdef _DEBUG
	static std::vector<sptr<Player>>* DEBUG_GetVectorOfPlayers() { return &allPlayers; }
	static std::vector<sptr<Team>>* DEBUG_GetVectorOfTeams(){ return &allTeams; }
#endif

	static tm GetWorldTime() { return WorldTime; }
	static std::string GetWorldTimeStr();

private:
	static std::vector<sptr<Player>> allPlayers;
	static std::vector<sptr<Team>> allTeams;

	static tm WorldTime;

};

