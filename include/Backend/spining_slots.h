#pragma once
#include "../../include/Backend/state_machine.h"
#include <iostream>
#include "../../include/Backend/spin.h"
#include "../../include/Backend/timer.h"
#include "../../include/Graphics/graphic_objects.h"
#include "../../include/View/display.h"
#include "../../include/Controller/controller.h"

class SpiningSlots: public StateMachine {
	std::vector<Spin>& m_rollers; 
	std::pair<std::shared_ptr<Timer>,std::shared_ptr<Timer>> m_timer_ptr;
	std::shared_ptr<Display> m_display_ptr;
	std::shared_ptr<Controller> m_controller_ptr;
	GraphicObjects& m_graphic_objects;
	bool m_spin_rollers = true;
public:
	SpiningSlots(std::vector<Spin>&, std::pair<std::shared_ptr<Timer>, std::shared_ptr<Timer>>&, GraphicObjects&, std::shared_ptr<Display>& , std::shared_ptr<Controller>& );
	void makeAction() override;
};