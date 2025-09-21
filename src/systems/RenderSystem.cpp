#pragma once

#include "RenderSystem.h"

//NON DECOMMENTARE LE INCLUSIONI SpriteComponent.h e TransformComponent.h! 
// per evitare ricorsioni circolari sono gestite in RenderingSystem.h con forward declaration
// -----------------------------
#include "SpriteComponent.h"
#include "TransformComponent.h"
// -----------------------------
//struct SpriteComponent;
//struct TransformComponent;
// -----------------------------

void RenderSystem::update(entt::registry& registry, sf::RenderWindow& window) {

	//con registry.view<component_1, component_2> viene creata una view che contiene tutte le entità con i component 1 e 2
	auto view = registry.view<TransformComponent, SpriteComponent>(); 

	//itero su ogni elemento della view e opero sulle variabili entity, component_1, component_2 della view
	for (auto [entity,transform,sprite]:view.each())
	{
		// Aggiorna la posizione dello sprite in base al componente Position
		sprite.sprite.setPosition(transform.position);

		// Disegna lo sprite sulla finestra
		window.draw(sprite.sprite);
	}
}
