#include <iostream>
#include "Application.h"

int main()
{
    Application app(DisplayConfig(sf::Vector2u(1600, 900), 32), "Test Finestra SFML");
    app.run();

    return EXIT_SUCCESS;
}