#pragma once

#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

struct SpriteComponent {
    sf::Sprite sprite;                                 // L’oggetto disegnabile di SFML che contiene posizione, texture e transform
    std::shared_ptr<sf::Texture> texture{ nullptr };   // Gestione sicura della texture condivisa da mantenere viva altrove (ResourceManager)

    bool visible{ true };            // Flag per abilitare/disabilitare il rendering di questa entità

    // Costruttore di default
    SpriteComponent() = default;

    // Costruttore comodo per assegnare subito la texture
    explicit SpriteComponent(const std::shared_ptr<sf::Texture> & tex) : texture(tex), sprite(*tex) {

        if (texture) {
            sprite.setTexture(*texture);
        }
    }
};

//// ESEMPIO: COME CARICARE UNA TEXTURE CON RESOURCE MANAGER?
//
// - Carico la texture nel ResourceManager e ottengo uno shared_ptr
//  
// auto playerTexture = resourceManager.getTexture("path/to/asset/player.png");
//
// - Creo il componente assegnando subito la texture
//  
// registry.emplace<SpriteComponent>(entity, playerTexture);
// 
// - Ora puoi accedere al componente
// 
// auto& spriteComp = registry.get<SpriteComponent>(player);
//
// spriteComp.sprite.setPosition(100.f, 200.f); // esempio di uso

