#pragma once

#include <entt.hpp>
#include <SFML/Window.hpp>

class PlayerController
{
public:
	PlayerController() {};

	void update(entt::registry& registry);

};