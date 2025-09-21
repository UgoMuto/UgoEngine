#pragma once

#include <entt.hpp>
#include <SFML/Window.hpp>
#include "InputComponent.h"

class InputSystem
{
public:
	InputSystem() {};
	
	void update(sf::Window& window, entt::registry& registry);

};