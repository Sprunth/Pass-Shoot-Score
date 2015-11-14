#pragma once

#include "Globals.h"
#include <boost/uuid/uuid_generators.hpp>

///Base class for all objects in the PSS world.
class WorldObject
{
public:
	WorldObject();
	virtual ~WorldObject();

	
	boost::uuids::uuid GetID() { return ID; }

private:
	static boost::uuids::random_generator id_gen;

	boost::uuids::uuid ID;

};

