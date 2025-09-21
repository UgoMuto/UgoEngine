#pragma once

#include "SFML/System/Vector2.hpp"

struct TransformComponent {
    sf::Vector2f position{ 0.f, 0.f };   // Posizione 2D nel mondo di gioco, di default all'origine
    sf::Vector2f scale{ 1.f, 1.f };      // Fattore di scala per ingrandire/ridurre l'entità
    float rotation{ 0.f };               // Angolo di rotazione in gradi (SFML lavora in gradi)

    // Costruttore di default
    TransformComponent() = default;

    // Costruttore parametrico per comodità
    TransformComponent(const sf::Vector2f& pos, const sf::Vector2f& scl = { 1.f, 1.f }, float rot = 0.f)
        : position(pos), scale(scl), rotation(rot) {
    }
};

// ESEMPIO
// 
// registry.emplace<TransformComponent>(entity, {100, 200}, {2, 2}, 45.f);