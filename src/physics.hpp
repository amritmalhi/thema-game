#ifndef PHYSICS_HPP
#define PHYSICS_HPP
class physics
{
public:
	physics() {}
	virtual void gravity() = 0;
	virtual void update_gravity() = 0;
};

#endif
