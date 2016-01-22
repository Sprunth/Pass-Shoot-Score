#include "WorldDB.h"

std::vector<sptr<Player>> WorldDB::allPlayers;
std::vector<sptr<Team>> WorldDB::allTeams;

TimeManager WorldDB::tmgr;
std::multimap<tm, std::pair<std::function<void(EventType)>&, EventType>, tm_comparer> WorldDB::eventMaster;

void WorldDB::NewWorld()
{
	srand(time(nullptr));

	allPlayers.clear();
	allTeams.clear();

	tmgr = TimeManager();
	eventMaster.clear();
}

void WorldDB::LoadWorld()
{
	
}

void WorldDB::Simulate(bool &stop)
{	
	tmgr.IncrementHour();

	/// Get all the events have registered to happen this hour
	auto erange = eventMaster.equal_range(tmgr.GetWorldTime());
	for (auto it = erange.first; it != erange.second; ++it)
	{
		/// For every registered event, call the callback
		auto func = it->second.first;
		auto envtType = it->second.second;

		func(envtType);
	}
	// we have processed them all, so remove them.
	eventMaster.erase(tmgr.GetWorldTime());

	/// Todo: somehow allow callbacks to enter a 'block' queue of things that must be resolved
	/*if (rand() % 50 == 1)
		stop = true;*/

	bool opened;
	
	ImGui::SetNextWindowPosCenter();
	ImGui::SetNextWindowSize(ImVec2(200, 100));
	ImGui::Begin("Simulating", &opened, ImGuiWindowFlags_Modal | ImGuiWindowFlags_NoResize|
		ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
	ImGui::Text("Simulating");
	ImGui::Separator();
	ImGui::Text(tmgr.GetWorldTimeStr("%b %d, %Y").c_str());
	ImGui::SameLine(160);
	if (ImGui::Button("Stop"))
	{
		stop = true;
	}
	ImGui::End();
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

void WorldDB::RegisterEvent(tm time, std::function<void(EventType)>& f, EventType e)
{
	eventMaster.insert(std::pair<tm, std::pair<std::function<void(EventType)>&, EventType>>
		(time, std::pair<std::function<void(EventType)>&, EventType>(f, e)));
}


std::string WorldDB::GetWorldTimeStr()
{
	return tmgr.GetWorldTimeStr();
}
