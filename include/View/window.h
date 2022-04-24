#pragma once
#include "display.h"
#include "../../include/config.h"
#include "../Graphics/graphic_objects.h"

class Window: public Display {
	sf::RenderWindow m_window { sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SlotMachineOGS", sf::Style::Close | sf::Style::Titlebar };
	GraphicObjects m_graphic_objects;
public:
	sf::RenderWindow* getWindowPtr();
	void render(const std::shared_ptr<Model>&) override;
	bool isOpen() const override;
};