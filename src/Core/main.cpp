//-------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------MAIN-------------------------------------------------------------------

#include <iostream>
#include "Application.h"

int main()
{

    Application app(DisplayConfig(sf::Vector2u(800, 600), 32), "Test Finestra SFML");
    app.run();



    return EXIT_SUCCESS;
}

// # Separare movimento da InputSystem
// - InputSystem gestisce solo input grezzi
// - MovementSystem applica movimento alle entità con Transform/Velocity

// # Aggiungere sistema di collisioni
// - CollisionComponent: bounding box, layer/tag
// - CollisionSystem: rileva e gestisce collisioni
// - (Opzionale) PhysicsSystem: gravità, rimbalzi, frizione

// # Modularizzare le demo
// - Ogni demo istanzia entità e sistemi in modo isolato
// - Usare factory/builder per creare entità
// - DemoManager per gestire init, update e switch tra demo

// # Interfaccia e gestione tempo
// - MenuSystem per UI e navigazione
// - TimeSystem con deltaTime e gestione pausa

// # Audio
// - AudioComponent e AudioSystem per effetti e musica
// - Condivisione risorse audio con ResourceManager via SharePoint

// # Configurazione e editor livelli
// - Caricamento path texture/audio da file di testo
// - Editor livelli: genera entità parametrizzate da file

//
//#include <iostream>
//#include <SFML/Graphics.hpp>
//
//int main() {
//
//    // Crea una finestra di 800x600 pixel con titolo
//    sf::RenderWindow window(sf::VideoMode(sf::Vector2u {800,600}, 32), "Figure Geometriche con SFML");
//
//    // Imposta il frame rate
//    window.setFramerateLimit(60);
//
//    // Crea un cerchio
//    sf::CircleShape cerchio(50); // raggio 50
//    cerchio.setFillColor(sf::Color::Red);
//    cerchio.setPosition(sf::Vector2f{ 100,100});
//
//    // Crea un rettangolo
//    sf::RectangleShape rettangolo(sf::Vector2f(120, 60));
//    rettangolo.setFillColor(sf::Color::Blue);
//    rettangolo.setPosition(sf::Vector2f{ 300,100 });
//
//    // Crea un triangolo (usando ConvexShape)
//    sf::ConvexShape triangolo;
//    triangolo.setPointCount(3);
//    triangolo.setPoint(0, sf::Vector2f(0, 0));
//    triangolo.setPoint(1, sf::Vector2f(100, 0));
//    triangolo.setPoint(2, sf::Vector2f(50, 100));
//    triangolo.setFillColor(sf::Color::Red);
//    triangolo.setPosition(sf::Vector2f{ 500,100 });
//
//    while (window.isOpen())
//    {
//
//        while (const auto event = window.pollEvent())
//        {
//            if (event->is<sf::Event::Closed>())
//            {
//                window.close();
//            }
//            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
//            {
//                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
//                    window.close();
//            }
//        }
//
//        // Pulisce la finestra
//        window.clear(sf::Color::White);
//
//        // Disegna le figure
//        window.draw(cerchio);
//        window.draw(rettangolo);
//        window.draw(triangolo);
//
//        // Mostra il contenuto disegnato
//        window.display();
//    }
//
//    return 0;
//}
