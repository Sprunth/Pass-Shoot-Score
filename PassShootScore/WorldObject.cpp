#include "WorldObject.h"

boost::uuids::random_generator WorldObject::id_gen;


WorldObject::WorldObject()
{
	ID = id_gen();
}


WorldObject::~WorldObject()
{

}
