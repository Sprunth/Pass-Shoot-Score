#include "TeamView.h"


TeamView::TeamView()
{
	SetPos(100, 50);
}


TeamView::~TeamView()
{
}


void TeamView::LoadTeam(sptr<Team> team)
{
	SetTitle(team->GetName());

	CurrentlyLoadedTeam = team;
}

void TeamView::DrawView()
{
	if (!CurrentlyLoadedTeam)
		return;

	ImGui::Columns(2);
	ImGui::Text("Name"); ImGui::NextColumn();
	ImGui::Text("Age"); ImGui::NextColumn();
	ImGui::Separator();

	for (auto player : CurrentlyLoadedTeam->GetPlayers())
	{
		ImGui::Text(player->GetName().c_str()); ImGui::NextColumn();
		if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0))
		{
			std::cout << "clicked " << player->GetName() << std::endl;
		}
		ImGui::Text(std::to_string(player->GetAge()).c_str()); ImGui::NextColumn();
	}

}
