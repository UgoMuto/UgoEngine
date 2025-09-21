#include <iostream>

#include "Application.h"
#include "myFirstComponents.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "RenderSystem.h"
#include "ResourceManager.h"
#include "VelocityComponent.h"
#include "TagComponent.h"


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

Application::Application(const DisplayConfig & config, const std::string & title)
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

	auto stars = m_registry.create();
	auto planet = m_registry.create();

	std::cout << "Creo Resource Manager" << std::endl; 

	//non mi piace, il resManager deve essere un membro privato della classe application
	//potrei instanziarlo in init() o ancora meglio nel costruttore inline, in ogni caso devo creare ResoriceManager& ResourceManager.instance()

	ResourceManager resManager = ResourceManager::instance();

	std::cout << "Assegnazione componenti" << std::endl;

	//non mi piace, bettori posizione, vettori scaling, path delle texture deve essere tutto caricato da file.
	//devo creare anche una system che funge da spawner

	std::string starsTexturePath = "resources\\texture\\stars.png";
	std::string planetTexturePath = "resources\\texture\\planet.png";

	m_registry.emplace<TransformComponent>(stars, sf::Vector2f(0, 0), sf::Vector2f(10, 10), 0.f);
	m_registry.emplace<VelocityComponent>(stars, sf::Vector2f(0, 0));
	m_registry.emplace<SpriteComponent>(stars,resManager.getTexture(starsTexturePath));
	
	m_registry.emplace<TransformComponent>(planet, sf::Vector2f(400, 300), sf::Vector2f(10, 10), 0.f);
	m_registry.emplace<VelocityComponent>(planet, sf::Vector2f(0, 0));
	/*m_registry.emplace<PlayerTag>(planet);*/
	m_registry.emplace<SpriteComponent>(planet,resManager.getTexture(planetTexturePath));

}

void Application::run() {

	std::cout << "Application.run()" << std::endl;
	//serve un controllo su questo while, la finestra deve chiudersi se premo ESC
		//Bug: se la finestra va in secondo piano, poi non torna più in primo piano in alcuno modo
		//ovviamente deve tornare in primo piano se la clicco o se faccio Alt+TAB
	while (m_window.isOpen())
	{

		while (const auto event =  m_window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				m_window.close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
					m_window.close();
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

