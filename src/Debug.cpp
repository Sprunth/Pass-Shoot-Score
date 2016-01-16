#include "Debug.h"


Debug::Debug()
{
}


Debug::~Debug()
{
}


void Debug::Draw()
{
	bool open;
	if (ImGui::Begin("Debug", &open, ImGuiWindowFlags_NoCollapse))
	{


		if (ImGui::Button("Add Player"))
		{
			auto player = PlayerFactory::CreatePlayer();

			auto teams = WorldDB::DEBUG_GetVectorOfTeams();
			auto team = teams->operator[](0);

			team->AddPlayer(player);
		}

		ImGui::End();
	}
}


