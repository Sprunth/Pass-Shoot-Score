#include "PlayerFactory.h"

PlayerFactory* PlayerFactory::activeFactory;

PlayerFactory::PlayerFactory()
{
	activeFactory = this;
}


PlayerFactory::~PlayerFactory()
{
}


sptr<Player> PlayerFactory::CreatePlayer()
{
	auto player = std::make_shared<Player>();

	WorldDB::RegisterPlayer(player);

	return player;
}


