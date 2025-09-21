#pragma once
#include <SFML/Graphics.hpp>

struct DisplayConfig
{
	sf::Vector2u resolution;
	unsigned int bitsPerPixel;

	DisplayConfig(const sf::Vector2u& res, const unsigned int bpp) {
		resolution = res;
		bitsPerPixel = bpp;
	}
};