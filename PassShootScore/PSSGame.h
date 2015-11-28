#pragma once

#include "Globals.h"
#include "GUI.h"
#include "TopMenu.h"

#include "WorldDatabase.h"
#include "WorldObjectFactory.h"

#include "Team.h"
#include "Player.h"

#include "PlayerView.h"
#include "TeamView.h"

class PSSGame
{
public:
	PSSGame();
	~PSSGame();

	void Init();
	void Run();

	GLFWwindow* window;

private:
	PlayerView playerView;
	TeamView teamView;

};

