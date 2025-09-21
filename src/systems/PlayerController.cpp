#include "PlayerController.h"
#include "InputComponent.h"
#include "VelocityComponent.h"
#include "TagComponent.h"

//void PlayerController::update(entt::registry& registry) {
//    auto group = registry.group<InputComponent, VelocityComponent, PlayerTag>();
//    
//
//    registry.view<InputComponent,VelocityComponent,PlayerTag>().each([](auto& comp) {
//
//        if (input.up) comp.vvelocity.y -= 1.0f;
//        if (input.down) vel.velocity.y += 1.0f;
//        if (input.right) vel.velocity.x += 1.0f;
//        if (input.left) vel.velocity.x -= 1.0f;
//        });
//}


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