#pragma once

#include <SFML/Window/Keyboard.hpp> // per la gestione dei tasti
#include <SFML/Window/Mouse.hpp>    // opzionale se usi anche il mouse

struct InputComponent {
    // Movimento basilare: direzioni cardinali
    bool up = false;  // true se il tasto "su" � premuto
    bool down = false;  // true se il tasto "gi�" � premuto
    bool left = false;  // true se il tasto "sinistra" � premuto
    bool right = false;  // true se il tasto "destra" � premuto

    // Azioni generiche: salto, attacco, interazione, da espandere per altri controlli
    bool jump = false;  // utile per platformer
    bool fire = false;  // utile per combat
    bool use = false;  // utile per interazioni

    bool pause = false;

    // Ultima direzione di input (pu� servire per animazioni o facing)
    sf::Vector2i lastDirection{ 0, 0 };

    // Costruttore di default
    InputComponent() = default;
};