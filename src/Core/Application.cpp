#include <iostream>

#include "Application.h"
#include "myFirstComponents.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "RenderSystem.h"
#include "ResourceManager.h"
#include "VelocityComponent.h"
#include "TagComponent.h"

#include <windows.h> //header per aggiungere una finestra di sistema per uscire dal gioco. Poco portabile(funziona solo con windows); Temporaneo, sarebbe bello fare una finestra personalizzata.
#pragma comment(lib, "User32.lib")  //pragma necessario per poter chiamare l'header precedente


Application::Application()
	: m_window(sf::VideoMode(sf::Vector2u(800, 600), 32), "Test Finestra SFML")
	, m_renderSystem()
	, m_inputSystem()
	, m_movementSystem()
	/*, m_playerController()*/
	, m_config(DisplayConfig(sf::Vector2u(800, 600), 32))
	, m_title("Test Finestra SFML")
{

	init();
	createDemoEntities();
}

Application::Application(const DisplayConfig& config, const std::string& title)
	: m_window(sf::VideoMode(config.resolution, config.bitsPerPixel), title)
	, m_renderSystem()
	, m_inputSystem()
	, m_movementSystem()
	/*, m_playerController()*/
	, m_config(config)
	, m_title(title)
{
	init();
	createDemoEntities();
}


void Application::init() {

	std::cout << "Application.Init()" << std::endl;

	m_window.setVerticalSyncEnabled(true);
}

void Application::createDemoEntities() {


	std::cout << "Generazione entità" << std::endl;

	auto bg_close = m_registry.create();
	auto player = m_registry.create();
	auto planet = m_registry.create();

	std::cout << "Creo Resource Manager" << std::endl;

	//non mi piace, il resManager deve essere un membro privato della classe application
	//potrei instanziarlo in init() o ancora meglio nel costruttore inline, in ogni caso devo creare ResoriceManager& ResourceManager.instance()

	ResourceManager resManager = ResourceManager::instance();

	std::cout << "Assegnazione componenti" << std::endl;

	//non mi piace, bettori posizione, vettori scaling, path delle texture deve essere tutto caricato da file.
	//devo creare anche una system che funge da spawner

	std::string bg_closeTexturePath = "resources\\texture\\bg_close.png";
	std::string playerTexturePath = "resources\\texture\\player.png";
	std::string planetTexturePath = "resources\\texture\\planet.png";

	m_registry.emplace<TransformComponent>(planet, sf::Vector2f(50, 50), sf::Vector2f(3.2, 3.2), 0.f);
	m_registry.emplace<VelocityComponent>(planet, sf::Vector2f(0, 0));
	m_registry.emplace<SpriteComponent>(planet, resManager.getTexture(planetTexturePath));

	m_registry.emplace<TransformComponent>(bg_close, sf::Vector2f(0, 0), sf::Vector2f(3.2, 3.2), 0.f);
	//m_registry.emplace<VelocityComponent>(stars, sf::Vector2f(0, 0));
	m_registry.emplace<SpriteComponent>(bg_close, resManager.getTexture(bg_closeTexturePath));

	m_registry.emplace<TransformComponent>(player, sf::Vector2f(400, 300), sf::Vector2f(2, 2), 0.f);
	m_registry.emplace<VelocityComponent>(player, sf::Vector2f(0, 0));
	/*m_registry.emplace<PlayerTag>(player);*/
	m_registry.emplace<SpriteComponent>(player,resManager.getTexture(playerTexturePath));

}

void Application::run() {

	std::cout << "Application.run()" << std::endl;
	//serve un controllo su questo while, la finestra deve chiudersi se premo ESC
		//Bug: se la finestra va in secondo piano, poi non torna più in primo piano in alcuno modo
		//ovviamente deve tornare in primo piano se la clicco o se faccio Alt+TAB
	while (m_window.isOpen())
	{

		while (const auto event = m_window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				m_window.close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
					if (MessageBoxA(
						NULL,
						"Sicuro di voler uscire?",
						"Un'altra mezz'ora e stacco",
						MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2
					) == IDYES)
					{
						m_window.close();
					}
				}
			}
		}

		m_inputSystem.update(m_window, m_registry); // cambiare l'ordine deli argomenti, mi da fastidio
		m_movementSystem.update(m_registry);
		/*m_playerController.update(m_registry);*/

		m_window.clear();

		m_renderSystem.update(m_registry, m_window);

		m_window.display();
	}
}