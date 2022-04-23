#pragma once
#include "../View/window.h"
#include "../Controller/pk_controller.h"

class Game {
	std::shared_ptr<Display> m_display_ptr;
	std::shared_ptr<Controller> m_controller_ptr;
public:
	Game();
	void gameLoop();
};