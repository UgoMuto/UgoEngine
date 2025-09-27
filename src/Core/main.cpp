
#include <iostream>
#include "Application.h"

int main()
{

    Application app(DisplayConfig(sf::Vector2u(800, 600), 32), "Test Finestra SFML");
    app.run();



    return EXIT_SUCCESS;
}
