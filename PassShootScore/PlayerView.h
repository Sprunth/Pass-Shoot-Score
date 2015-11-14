#pragma once

#include "View.h"
#include "Player.h"

class PlayerView :
	public View
{
public:
	PlayerView();
	~PlayerView();

	void LoadPlayer(sptr<Player> player);

private:

	void DrawView() override;

	sptr<Player> currentlyLoadedPlayer;
};

