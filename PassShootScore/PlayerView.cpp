#include "PlayerView.h"

using namespace ImGui;

PlayerView::PlayerView()
{
	SetPos(600, 50);
}


PlayerView::~PlayerView()
{
}

void PlayerView::LoadPlayer(sptr<Player> player)
{
	SetTitle(player->GetName());

	currentlyLoadedPlayer = player;
}

void PlayerView::DrawView()
{
	if (!currentlyLoadedPlayer)
		return;

	Text((boost::format("Age: %1%") % currentlyLoadedPlayer->GetAge()).str().c_str()); 
	Text((boost::format("Team: %1%") % currentlyLoadedPlayer->GetTeam()->GetName()).str().c_str());
}

