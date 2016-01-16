#include "WorldObject.h"

boost::uuids::random_generator WorldObject::uuid_gen = boost::uuids::random_generator();

WorldObject::WorldObject()
{
	ID = uuid_gen();
}


WorldObject::~WorldObject()
{
}
