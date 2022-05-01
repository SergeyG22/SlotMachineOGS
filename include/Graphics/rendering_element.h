#define _GLIBCXX_USE_CXX11_ABI 1
#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>


class RenderingElement {
	std::string m_file_name;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
public:
	RenderingElement(const std::string&);
	sf::Sprite* getSprite();
};


