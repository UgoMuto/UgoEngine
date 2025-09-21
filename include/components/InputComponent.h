#pragma once

#include <SFML/Window/Keyboard.hpp> // per la gestione dei tasti
#include <SFML/Window/Mouse.hpp>    // opzionale se usi anche il mouse

struct InputComponent {
    // Movimento basilare: direzioni cardinali
    bool up = false;  // true se il tasto "su" è premuto
    bool down = false;  // true se il tasto "giù" è premuto
    bool left = false;  // true se il tasto "sinistra" è premuto
    bool right = false;  // true se il tasto "destra" è premuto

    // Azioni generiche: salto, attacco, interazione, da espandere per altri controlli
    bool jump = false;  // utile per platformer
    bool fire = false;  // utile per combat
    bool use = false;  // utile per interazioni

    bool pause = false;

    // Ultima direzione di input (può servire per animazioni o facing)
    sf::Vector2i lastDirection{ 0, 0 };

    // Costruttore di default
    InputComponent() = default;
};