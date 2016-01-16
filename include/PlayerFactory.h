#pragma once

#include "WorldDB.h"
#include "WorldObjectFactory.h"
#include "Player.h"

class PlayerFactory :
	public WorldObjectFactory
{
public:
	PlayerFactory();
	~PlayerFactory();

	static sptr<Player> CreatePlayer();

private:
	static PlayerFactory* activeFactory;
};

