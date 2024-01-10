#pragma once
#include<random>
#include"sc_math.h"
class Random
{
public:

	static int Int(int min, int max);
	static float Float(float min, float max);
		   
	static Vector3f vector3f(float&& min, float&& max);
	static Vector3f vector3i(float&& min, float&& max);
	static Vector2f vector2f(float& min, float& max);

private:
	Random() {};
	Random(const Random&) = delete;

	static Random& getRand()
	{
		static Random r_instance;
		r_instance.randomize();
		return r_instance;
	}

	std::default_random_engine& global_urng()
	{
		static std::default_random_engine u{};
		return u;
	}

	void randomize()
	{
		static std::random_device rd{};
		global_urng().seed(rd());
	}

	int IInt(int min, int max);
	float IFloat(float min, float max);
};

