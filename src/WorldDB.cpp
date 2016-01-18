#include "WorldDB.h"

std::vector<sptr<Player>> WorldDB::allPlayers;
std::vector<sptr<Team>> WorldDB::allTeams;

TimeManager WorldDB::tmgr;

void WorldDB::NewWorld()
{
	allPlayers.clear();
	allTeams.clear();

	tmgr = TimeManager();
}

void WorldDB::LoadWorld()
{
	
}

void WorldDB::Simulate(bool &stop)
{
	// Todo: some sort of event queue per day, sorted by hour
	
	tmgr.IncrementHour();

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

std::string WorldDB::GetWorldTimeStr()
{
	return tmgr.GetWorldTimeStr();
}
