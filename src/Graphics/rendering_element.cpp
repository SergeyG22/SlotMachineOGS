#include "Graphics/rendering_element.h"

RenderingElement::RenderingElement(const std::string& file_name) {
	if (!m_texture.loadFromFile("../resources/images/" + file_name)) {
		std::cerr << "error loading the " << file_name << " file";
	}
	m_file_name = file_name;
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(sf::Vector2f(0, 0));
}

sf::Sprite* RenderingElement::getSprite() {
	return &m_sprite;
}
