#pragma once

#include "View.h"
#include "Team.h"
#include "Player.h"

class TeamView : public View
{
public:
	TeamView();
	~TeamView();

	void LoadTeam(sptr<Team> team);

private:

	sptr<Player> SelectedPlayer;

	void DrawView() override;

	sptr<Team> CurrentlyLoadedTeam;
};

