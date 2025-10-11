#pragma once


#include <entt.hpp>
#include <SFML/Window.hpp>
#include "InputComponent.h"
#include "TransformComponent.h"

class PlayerController
{
public:
	PlayerController() {};

	void update(entt::registry& registry);

};