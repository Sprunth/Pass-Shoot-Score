#include "Player.h"


Player::Player()
{
	std::stringstream ss;
	ss << GetID();
	SetName(ss.str());
}


Player::~Player()
{
}
