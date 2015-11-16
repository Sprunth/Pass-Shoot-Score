#pragma once

#include "Globals.h"

class WorldObject;
class Player;
class Team;

class WorldDatabase
{
public:
	static void InitializeDatabase();
	static WorldDatabase* GetActiveDatabase() { return ActiveDatabase.get(); }

	WorldDatabase();
	~WorldDatabase();

	void AddWorldObject(sptr<WorldObject> o);
	void AddPlayer(sptr<Player> p);
	void AddTeam(sptr<Team> t);


	//test
	std::map<boost::uuids::uuid, sptr<WorldObject>> GetAllWorldObjects() const
	{
		return worldObjects;
	}

private:

	static std::unique_ptr<WorldDatabase> ActiveDatabase;

	std::map<boost::uuids::uuid, sptr<WorldObject>> worldObjects;
	// todo: use a prefix tree
	//std::map<std::string, sptr<WorldObject>> objLookup;

	std::map<boost::uuids::uuid, sptr<Player>> players;
	std::map<boost::uuids::uuid, sptr<Team>> teams;
};

