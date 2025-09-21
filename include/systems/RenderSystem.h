#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <entt.hpp>

//Forward declaration dei componenti per evitare ricorsioni circolari

struct TransformComponent;
struct SpriteComponent;

class RenderSystem
{
public:
	RenderSystem() {};
	void update(entt::registry& registry, sf::RenderWindow& window);
};

