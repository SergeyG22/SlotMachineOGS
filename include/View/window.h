#pragma once
#include "display.h"
#include "../../include/config.h"

class Window: public Display {
	sf::RenderWindow m_window { sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SlotMachineOGS", sf::Style::Close | sf::Style::Titlebar };
public:
	sf::RenderWindow* getWindowPtr();
	void render() override;
	bool isOpen() const override;
};