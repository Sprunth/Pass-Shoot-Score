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
	/// Todo: Allow generating different types of players
	/// Different positions, different ages

	auto player = std::make_shared<Player>(static_cast<int>(15 + rand() % 15));

	std::stringstream ss;
	ss << player->GetID();
	player->SetName(ss.str());

	WorldDB::RegisterPlayer(player);

	return player;
}


