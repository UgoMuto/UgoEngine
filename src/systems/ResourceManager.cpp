//#pragma once
//
//#include "ResourceManager.h"
//
//	//contrololare il corretto utilizzo dello share_ptr
//std::shared_ptr<sf::Texture> ResourceManager::getTexture(const std::string& path) {
//	//ricerca nella unordered map di texture, ritornare lo shared_ptr che punta alla texture con il path indiacto
//	return 0;
//};
//

// ------------------------------------------ GENERATO CON GEMINI CONTROLLARE!!! -------------------------------------
#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <string>

#include "ResourceManager.h"
#include <iostream>

// Implementation of the static instance method using a local static variable.
// This is a thread-safe way to implement a singleton in C++11 and later.
ResourceManager& ResourceManager::instance()
{
    static ResourceManager instance;
    return instance;
}

// Implementation of the getTexture method.
std::shared_ptr<sf::Texture> ResourceManager::getTexture(const std::string& path)
{
    // Search the map for the texture.
    auto it = m_textures.find(path);

    // If the texture is already loaded, return the existing shared pointer.
    if (it != m_textures.end())
    {
        return it->second;
    }

    // If not found, create a new shared pointer and load the texture from the file.
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(path))
    {
        // Handle the error if the file cannot be loaded.
        std::cerr << "Error: Could not load texture from file " << path << std::endl;
        return nullptr; // Return a null pointer to indicate failure.
    }

    // Store the newly loaded texture in the map and return the shared pointer.
    m_textures[path] = texture;
    return texture;
}