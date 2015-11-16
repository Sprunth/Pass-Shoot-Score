#pragma once

#include "View.h"
#include "Team.h"
#include "Player.h"

#include <boost/format.hpp>

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

