#pragma once

#include <SFML/Graphics.hpp>
#include <entt.hpp>
#include "RenderSystem.h"
#include "DisplayConfig.h"
#include "InputSystem.h"
#include "MovementSystem.h"
#include "PlayerController.h"

class Application
{
public:

	Application();

	Application(const DisplayConfig& config, const std::string& title); //title crasha per determinati valori per esempio "window title", lo sa Dio perchè...
	
	~Application() = default;

	void run();

private:
	DisplayConfig m_config;
	std::string m_title;
	float m_timeStep = 1.0f / 60.f;
	
	RenderSystem m_renderSystem;		//To do: inizializzare nel costruttore!
	InputSystem m_inputSystem;
	MovementSystem m_movementSystem;
	/*PlayerController m_playerController;*/

	//PhysicsSystem m_physicsSystem;

	
	sf::RenderWindow m_window;
	entt::registry m_registry;
	void init();
	void createDemoEntities();
};