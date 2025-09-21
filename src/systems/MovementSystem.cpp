#include "MovementSystem.h"

#include <entt.hpp>
#include "VelocityComponent.h"

void MovementSystem::update(entt::registry& registry) {
   
    auto group = registry.group<TransformComponent, VelocityComponent>();

    for (auto [entity, trans, vel] : group.each()) {
        if (vel.velocity.x == 0 && vel.velocity.y == 0) continue;

        trans.position.x += vel.velocity.x;
        trans.position.y += vel.velocity.y;
    }
}