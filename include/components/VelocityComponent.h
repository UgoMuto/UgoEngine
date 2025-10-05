#pragma once

#include <SFML/System/Vector2.hpp>

struct VelocityComponent {
    sf::Vector2f velocity{ 0.f, 0.f }; // velocità in pixel/
};

//Il Movement System userà VelocityComponent per aggiornare Trasform Component
//L'input sistem cambierà la velocità dell'oggetto ma la sua posizione sarà gestita dal MovementSystem in accordo alla sua velocità