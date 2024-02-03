#pragma once

constexpr const int SCREEN_WIDTH = 1280;
constexpr const int SCREEN_HEIGHT = 720;

struct Vector2
{
	float	x;
	float	y;
};

struct Transform
{
	//void	operator=(Transform _val);
	//void	operator+=(Transform _val);
	int		x;
	int		y;
};

struct Size
{
	int		width;
	int		height;
};