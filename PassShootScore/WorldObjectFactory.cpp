#include "WorldObjectFactory.h"

#include "WorldDatabase.h"

#include "Team.h"
#include "Player.h"
#include "WorldObject.h"

using namespace std;

sptr<Player> WorldObjectFactory::CreatePlayer()
{
	auto p = make_shared<Player>();

	WorldDatabase::GetActiveDatabase()->AddPlayer(p);

	RegisterWorldObject(p);

	return p;
}

sptr<Team> WorldObjectFactory::CreateTeam()
{
	auto t = make_shared<Team>();

	WorldDatabase::GetActiveDatabase()->AddTeam(t);

	RegisterWorldObject(t);

	return t;
}

void WorldObjectFactory::RegisterWorldObject(sptr<WorldObject> obj)
{
	WorldDatabase::GetActiveDatabase()->AddWorldObject(obj);
}
