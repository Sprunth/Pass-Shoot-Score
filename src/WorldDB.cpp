#include "WorldDB.h"

std::vector<sptr<Player>> WorldDB::allPlayers;
std::vector<sptr<Team>> WorldDB::allTeams;

void WorldDB::RegisterPlayer(std::shared_ptr<Player> p)
{
	auto pos = std::find(allPlayers.begin(), allPlayers.end(), p);

	if (pos == allPlayers.end())
	{
		allPlayers.push_back(p);
	}
}

void WorldDB::RegisterTeam(std::shared_ptr<Team> t)
{
	auto pos = std::find(allTeams.begin(), allTeams.end(), t);

	if (pos == allTeams.end())
	{
		allTeams.push_back(t);
	}
}

