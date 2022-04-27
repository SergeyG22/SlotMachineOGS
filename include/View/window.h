#pragma once
#include "display.h"
#include "../../include/config.h"
#include "../Graphics/graphic_objects.h"
#include "../Backend/spin.h"
#include "../Backend/timer.h"

class Window: public Display {
	sf::RenderWindow m_window { sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SlotMachineOGS", sf::Style::Close | sf::Style::Titlebar };
	GraphicObjects& m_graphic_objects;
	std::vector<Spin>& m_rollers;
	sf::Clock clock;
public:
	sf::RenderWindow* getWindowPtr();
	void render(const std::shared_ptr<Model>&, std::shared_ptr<Timer>&) override;
	bool isOpen() const override;
	Window(std::vector<Spin>&, GraphicObjects&);
};