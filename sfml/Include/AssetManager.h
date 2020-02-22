#pragma once
#include<SFML\Graphics.hpp>
#include<map>
#include<assert.h>
class AssetManager {
public:
	AssetManager();
	static sf::Texture& GetTexture(std::string const& filename);

private:
	std::map<std::string, sf::Texture> m_Textures;
	static AssetManager* sInstance;
};