#pragma once

#include <SFML/Graphics/Rect.hpp>

struct ColliderComponent {
    sf::FloatRect bounds;  // rettangolo di collisione relativo al Transform
    bool isTrigger = false; // Se messo a true non blocca, ma serve rilevare la collisione. (in pratica ci passi attraverso ma puoi sempre triggerare qualcosa)
};