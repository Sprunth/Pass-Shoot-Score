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
	auto birthday = WorldDB::GetWorldTime();
	birthday -= boost::gregorian::years(15 + rand() % 4);
	birthday -= boost::gregorian::days(rand() % 365);

	auto player = std::make_shared<Player>(birthday);

	std::stringstream ss;
	ss << player->GetID();
	player->SetName(ss.str());

	WorldDB::RegisterPlayer(player);

	return player;
}


