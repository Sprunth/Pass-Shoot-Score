#include "WorldDB.h"

std::vector<sptr<Player>> WorldDB::allPlayers;
std::vector<sptr<Team>> WorldDB::allTeams;

tm WorldDB::WorldTime;

void WorldDB::NewWorld()
{
	allPlayers.clear();
	allTeams.clear();

	WorldTime = { 0, 0, 0, 1, 0, 116, 0, 0, 0 };
}

void WorldDB::LoadWorld()
{
	
}

void WorldDB::Simulate(bool &stop)
{
	// Todo: some sort of event queue per day, sorted by hour
	
	WorldTime.tm_hour += 1;
	mktime(&WorldTime);

	if (rand() % 5)
		stop = true;
}


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

std::string WorldDB::GetWorldTimeStr()
{
	std::stringstream ss;
	ss << std::put_time(&WorldTime, "%d-%m-%Y %H-%M");
	return ss.str();
}