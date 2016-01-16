#include "Debug.h"


Debug::Debug()
{
}


Debug::~Debug()
{
}


void Debug::Draw()
{
#ifdef _DEBUG

	bool open;
	ImGui::Begin("Debug", &open);
	ImGui::SetWindowSize(ImVec2(300, 400));
	ImGui::SetWindowPos(ImVec2(700, 50));
	
	if (ImGui::Button("Add Player"))
	{
		auto player = PlayerFactory::CreatePlayer();

		auto teams = WorldDB::DEBUG_GetVectorOfTeams();
		auto team = teams->operator[](0);
		
		team->AddPlayer(player);
	}

	ImGui::End();

#endif
}


