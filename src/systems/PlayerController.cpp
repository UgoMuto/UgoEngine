#include "PlayerController.h"
#include "InputComponent.h"
#include "VelocityComponent.h"
#include "TagComponent.h"

void PlayerController::update(entt::registry& registry) {

    registry.group<InputComponent, VelocityComponent, PlayerTag>().each([](auto& input, auto& vel, auto& ptag) {


        vel.x = 0.0f;
        vel.y = 0.0f;

        if (input.up) vel.y -= 15.0f;
        if (input.down) vel.y += 15.0f;
        if (input.right) vel.x += 15.0f;
        if (input.left) vel.x -= 15.0f;

        }
    );

}


//VECCHIA VERSIONE PRESENTE NELL'INPUT SSYSTEM'
// 
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up)) {
//    registry.view<VelocityComponent>().each([](auto& comp) { comp.velocity.y -= 1.f; });
//}
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) {
//    registry.view<VelocityComponent>().each([](auto& comp) { comp.velocity.x -= 1.f; });
//}
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)) {
//    registry.view<VelocityComponent>().each([](auto& comp) { comp.velocity.x += 1.f; });
//}
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) {
//    registry.view<VelocityComponent>().each([](auto& comp) { comp.velocity.y += 1.f; });
//}