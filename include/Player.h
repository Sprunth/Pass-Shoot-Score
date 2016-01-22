#pragma once

#include "Globals.h"

#include "Person.h"

class Player : public Person
{
public:
	Player(tm birthday);
	~Player();
};
