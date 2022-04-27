#pragma once
#include "../../include/Controller/controller.h"
#include "../../include/View/window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class PkController: public Controller {
	std::shared_ptr<Display>m_window_ptr;
	std::shared_ptr<Timer>m_timer_ptr;
	std::vector<Spin>& m_rollers;
	bool mouseEvent(const sf::Event&);
	bool keyboardEvent(const sf::Event&);
public:
	PkController(std::shared_ptr<Display>, std::vector<Spin>&, std::shared_ptr<Timer>&);
	void eventLoop() override;
};