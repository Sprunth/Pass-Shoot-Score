#include "TeamFactory.h"

TeamFactory* TeamFactory::activeFactory;

TeamFactory::TeamFactory()
{
	activeFactory = this;
}


TeamFactory::~TeamFactory()
{
}

sptr<Team> TeamFactory::CreateTeam()
{
	auto team = std::make_shared<Team>();

	WorldDB::RegisterTeam(team);

	return team;
}

