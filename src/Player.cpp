#include "Player.h"


Player::Player(PSSDate birthday) : Person(birthday)
{

}


Player::~Player()
{
}

void Player::InitSkills()
{
	AddSkill(std::vector<std::string>{
		"Shooting", "Passing", "Marking"
	});
}

