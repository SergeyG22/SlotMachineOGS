#pragma once
#include "../../include/Controller/controller.h"
#include "../../include/View/window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class PkController: public Controller {
	std::shared_ptr<Display> m_window_ptr;
	std::pair<std::shared_ptr<Timer>, std::shared_ptr<Timer>> m_timer_ptr;
	std::vector<Spin>& m_rollers;
	const GraphicObjects& m_graphic_objects_ptr;
	bool mouseEvent(const sf::Event&, const sf::Vector2f&);
	bool keyboardEvent(const sf::Event&);
public:
	PkController(std::shared_ptr<Display>, std::vector<Spin>&, std::pair<std::shared_ptr<Timer>, std::shared_ptr<Timer>>& m_timer_ptr, const GraphicObjects&);
	void eventLoop() override;
};