#pragma once

#include "Globals.h"
#include <boost/uuid/uuid_generators.hpp>

class WorldObjectFactory;

///Base class for all objects in the PSS world.
class WorldObject : protected std::enable_shared_from_this<WorldObject>
{
public:
	/// Use the WorldObjectFactory to create world objects!
	WorldObject();
	virtual ~WorldObject();
	
	boost::uuids::uuid GetID() { return ID; }
	std::string GetName() const { return name; }
	void SetName(std::string n) { name = n; }

private:
	static boost::uuids::random_generator id_gen;

	boost::uuids::uuid ID;
	std::string name;
};

