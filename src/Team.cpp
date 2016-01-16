#include "Team.h"


Team::Team()
{
}


Team::~Team()
{
}


void Team::AddPlayer(sptr<Player> p)
{
	players.push_back(p);
}

void Team::RemovePlayer(sptr<Player> p)
{
	auto pos = find(players.begin(), players.end(), p);
	players.erase(pos);
}


void Team::DrawTeamList()
{
	ImGui::Begin(GetName().c_str());
	ImGui::SetWindowSize(ImVec2(200, 400));

	// Gather all the player names
	std::vector<std::string> rowStrings;
	for (auto p : players)
	{
		// In the future we can have other fields besides name
		rowStrings.push_back(p->GetName());
	}
	std::vector<const char*> rows;
	std::transform(rowStrings.begin(), rowStrings.end(), std::back_inserter(rows), [](const std::string &s){return s.c_str(); });
	int currentItem;
	ImGui::ListBox(GetName().c_str(), &currentItem, &rows[0], rows.size());

	ImGui::End();
}

