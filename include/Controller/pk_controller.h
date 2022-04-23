#pragma once
#include "../../include/Controller/controller.h"
#include "../../include/View/window.h"
#include <SFML/Graphics.hpp>

class PkController: public Controller {
	std::shared_ptr<Display>m_window_ptr;
public:
	PkController(std::shared_ptr<Display>);
	void eventLoop() override;
};