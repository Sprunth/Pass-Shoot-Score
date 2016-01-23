#pragma once

#include "Globals.h"
#include <iomanip>
#include <map>

#include "TimeManager.h"

class Player;
class Team;

// types of events for the eventMaster to handle
enum class EventType
{
	PLAYER_BIRTHDAY
};

// tm has no comparer and we need one for the multimap
struct tm_comparer
{
	bool operator() (const tm & t1, const tm & t2) const
	{
		auto start = t1;
		auto end = t2;
		return difftime(mktime(&end), mktime(&start)) > 0;
	}
};

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

	static void RegisterEvent(tm time, std::function<void(EventType)>& f, EventType e);
	
	static std::string GetWorldTimeStr();
	static TimePoint GetWorldTime() { return tmgr.GetWorldTime(); }

private:
	static std::vector<sptr<Player>> allPlayers;
	static std::vector<sptr<Team>> allTeams;

	static TimeManager tmgr;

	/// Other game objects will add functions and the eventtype to return to the eventmaster,
	/// indexed by the time (tm) they need it called at.
	static std::multimap<tm, std::pair<std::function<void(EventType)>&, EventType>, tm_comparer> eventMaster;
};

