#pragma once

#include "InputSystem.h"
#include "VelocityComponent.h"
// inclusione da togliere:
#include "TransformComponent.h"

//Per adesso funge anche da MovimentSystem


void InputSystem::update(sf::Window& window, entt::registry& registry) 
{
	//Reset inputComponent flags
    registry.view<InputComponent>()
        .each([](auto& comp) {
        comp.up = false;
        comp.down = false;
        comp.left = false;
        comp.right = false;
        comp.fire = false;
        comp.jump = false;
        comp.use = false;
            });

    // da togliere perchè va gestito in un altro system, tipo player controller
    registry.view<VelocityComponent>()
        .each([](auto& comp) {
        comp.velocity.x = 0.0f;
        comp.velocity.y = 0.0f;
           });



    // gestire la mutua esclusivita dei tasti, studiare e valutare un approccio con buffer comandi

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up)) {
        registry.view<InputComponent>().each([](auto& comp) { comp.up = true; } );
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) {
        registry.view<InputComponent>().each([](auto& comp) { comp.left = true; });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)) {
        registry.view<InputComponent>().each([](auto& comp) { comp.right = true; });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) {
        registry.view<InputComponent>().each([](auto& comp) { comp.down = true; });
    }


    //DA CANCELLARE E EGESTIRE NEL PLAYER CONTROLLER
    // 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up)) {
        registry.view<VelocityComponent>().each([](auto& comp) { comp.velocity.y -= 1.f; });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) {
        registry.view<VelocityComponent>().each([](auto& comp) { comp.velocity.x -= 1.f; });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)) {
        registry.view<VelocityComponent>().each([](auto& comp) { comp.velocity.x += 1.f; });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) {
        registry.view<VelocityComponent>().each([](auto& comp) { comp.velocity.y += 1.f; });
    }
    
    }