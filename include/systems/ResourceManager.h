#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include <memory>
#include <unordered_map>

class ResourceManager
{
public:
    static ResourceManager& instance();

    std::shared_ptr<sf::Texture> getTexture(const std::string& path);

private:
    ResourceManager() = default;

    // La mappa ora usa shared_ptr per coerenza con il metodo di ritorno
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_textures;
};