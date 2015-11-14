#include "PlayerView.h"


PlayerView::PlayerView()
{
}


PlayerView::~PlayerView()
{
}

void PlayerView::LoadPlayer(sptr<Player> player)
{
	SetTitle(player->GetName());
}

void PlayerView::DrawView()
{
	
}

