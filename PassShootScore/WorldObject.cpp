#include "WorldObject.h"

#include "WorldDatabase.h"

boost::uuids::random_generator WorldObject::id_gen;


WorldObject::WorldObject()
{
	ID = id_gen();
}


WorldObject::~WorldObject()
{

}
