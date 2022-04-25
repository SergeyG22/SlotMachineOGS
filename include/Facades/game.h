#pragma once
#include "../View/window.h"
#include "../Controller/pk_controller.h"
#include "../Model/model.h"
#include "../Backend/spin.h"

class Game {
	std::shared_ptr<Display> m_display_ptr;
	std::shared_ptr<Controller> m_controller_ptr;
	std::shared_ptr<Model> m_model_ptr;
	std::vector<Spin>m_rollers { Spin { ROLLER_A_SPEED }, Spin { ROLLER_B_SPEED }, Spin { ROLLER_C_SPEED }, Spin { ROLLER_D_SPEED }, Spin { ROLLER_E_SPEED } };
	GraphicObjects m_graphic_objects;
public:
	Game();
	void gameLoop();
};