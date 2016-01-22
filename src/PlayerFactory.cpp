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

	/// generate a random birthday for this new player
	tm birthday = WorldDB::GetWorldTime();
	birthday.tm_year = rand() % 25 + 80;
	birthday.tm_mon = rand() % 11;
	birthday.tm_mday = rand() % 31;
	birthday.tm_hour = rand() % 23;
	mktime(&birthday);

	auto player = std::make_shared<Player>(birthday);

	std::stringstream ss;
	ss << player->GetID();
	player->SetName(ss.str());

	WorldDB::RegisterPlayer(player);

	return player;
}


