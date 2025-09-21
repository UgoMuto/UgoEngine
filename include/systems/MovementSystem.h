#pragma once

#include <entt.hpp>
#include <SFML/Window.hpp>
#include "InputComponent.h"
#include "TransformComponent.h"
class MovementSystem
{
public:
	MovementSystem() {};

	void update(entt::registry& registry);

};