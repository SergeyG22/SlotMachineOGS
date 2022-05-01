#pragma once
#include "../View/window.h"
#include "../Controller/pk_controller.h"
#include "../Model/model.h"
#include "../Backend/spin.h"
#include "../Backend/timer.h"
#include "../Backend/state_machine.h"
#include "../Backend/state_context.h"


class Game {
	GraphicObjects m_graphic_objects;
	std::shared_ptr<Model> m_model_ptr;
	std::shared_ptr<Display> m_display_ptr;
	std::shared_ptr<Controller> m_controller_ptr;
	std::vector<Spin>m_rollers { Spin { std::make_pair(ROLLER_A_MIN_SPEED, ROLLER_A_MAX_SPEED) }, 
							     Spin { std::make_pair(ROLLER_B_MIN_SPEED, ROLLER_B_MAX_SPEED) }, 
								 Spin { std::make_pair(ROLLER_C_MIN_SPEED, ROLLER_C_MAX_SPEED) }, 
								 Spin { std::make_pair(ROLLER_D_MIN_SPEED, ROLLER_D_MAX_SPEED) }, 
								 Spin { std::make_pair(ROLLER_E_MIN_SPEED, ROLLER_E_MAX_SPEED) } 
							   };
	std::vector<std::shared_ptr<StateMachine>>m_context;
	std::pair<std::shared_ptr<Timer>, std::shared_ptr<Timer>>m_timer_ptr;
public:
	Game();
	void gameLoop();
};