#pragma once

#include <SFML/System/Vector2.hpp>

struct VelocityComponent {
    sf::Vector2f velocity{ 0.f, 0.f }; // velocit� in pixel/
};

//Il Movement System user� VelocityComponent per aggiornare Trasform Component
//L'input sistem cambier� la velocit� dell'oggetto ma la sua posizione sar� gestita dal MovementSystem in accordo alla sua velocit�