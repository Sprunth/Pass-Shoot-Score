#include "WorldDatabase.h"

#include "WorldObject.h"
#include "Player.h"
#include "Team.h"

using namespace std;

std::unique_ptr<WorldDatabase> WorldDatabase::ActiveDatabase;

void WorldDatabase::InitializeDatabase()
{
	ActiveDatabase = make_unique<WorldDatabase>();
}


WorldDatabase::WorldDatabase()
{
}


WorldDatabase::~WorldDatabase()
{
}

void WorldDatabase::AddWorldObject(sptr<WorldObject> o)
{
	worldObjects.insert(pair<boost::uuids::uuid, sptr<WorldObject>>(o->GetID(), o));
}

void WorldDatabase::AddPlayer(sptr<Player> p)
{
	players.insert(pair<boost::uuids::uuid, sptr<Player>>(p->GetID(), p));
}

void WorldDatabase::AddTeam(sptr<Team> t)
{
	teams.insert(pair<boost::uuids::uuid, sptr<Team>>(t->GetID(), t));
}
