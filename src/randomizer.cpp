#include "randomizer.h"

int Random::Int(int min, int max)
{
	return getRand().IInt(min, max);
}

float Random::Float(float min, float max)
{	
	return getRand().IFloat(min, max);
}

Vector3f Random::vector3f(float&& min, float&& max)
{
	return Vector3f(Float(min, max), Float(min, 0.5),
		Float(min, max));
}

Vector3f Random::vector3i(float&& min, float&& max)
{
	return Vector3f(Int(min, max), Int(min, max),
		Int(min, max));
}

Vector2f Random::vector2f(float& min, float& max)
{
	return Vector2f(Float(min, max), Float(min, max));
}

int Random::IInt(int min, int max)
{
	static std::uniform_int_distribution<int> d{};
	using parm_t = decltype(d)::param_type;
	return d(global_urng(), parm_t{ min, max });
}

float Random::IFloat(float min, float max)
{
	static std::uniform_real_distribution<float> d{};
	using parm_t = decltype(d)::param_type;
	return d(global_urng(), parm_t{ min, max });
}
