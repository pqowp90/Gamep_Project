#pragma once
class Game_Math
{
public:
	static float Game_Lerp(float A, float B, float Alpha)
	{
		return A * (1 - Alpha) + B * Alpha;
	}
};

