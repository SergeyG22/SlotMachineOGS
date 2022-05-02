#pragma once
#include "../../include/Backend/state_machine.h"
#include "../../include/Graphics/graphic_objects.h"
#include "../../include/View/display.h"
#include "../../include/Controller/controller.h"
#include <iostream>

class ShowResult: public StateMachine {
	std::shared_ptr<Display> m_display_ptr;
	GraphicObjects& m_graphic_objects;
	std::shared_ptr<Controller> m_controller_ptr;
	double m_alpha = 0.0;
	double m_boost_step = 2.5;
	int m_booster = 0;
	int m_flickers_counter = 0;
	void resetSettings();
public:
	ShowResult(GraphicObjects&, std::shared_ptr<Display>&, std::shared_ptr<Controller>& );
	void makeAction() override;
};