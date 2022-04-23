#pragma once
#include "../../include/Controller/controller.h"
#include "../../include/View/window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class PkController: public Controller {
	std::shared_ptr<Display>m_window_ptr;
	bool mouseEvent(const sf::Event&);
	bool keyboardEvent(const sf::Event&);
public:
	PkController(std::shared_ptr<Display>);
	void eventLoop() override;
};