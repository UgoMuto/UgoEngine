#pragma once
#include <SFML/System/Vector2.hpp>

struct Position
{
	sf::Vector2f pos;

	Position(float x = 0.f, float y = 0.f)
		:pos(sf::Vector2f(x, y)) {
	}
};