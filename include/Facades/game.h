#pragma once
#include "../View/window.h"
#include "../Controller/pk_controller.h"
#include "../Model/model.h"

class Game {
	std::shared_ptr<Display> m_display_ptr;
	std::shared_ptr<Controller> m_controller_ptr;
	std::shared_ptr<Model> m_model_ptr;
public:
	Game();
	void gameLoop();
};