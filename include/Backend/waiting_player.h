#pragma once
#include "../../include/Backend/state_machine.h"
#include "../../include/Controller/controller.h"
#include <iostream>

class WaitingForPlayer: public StateMachine {
	std::shared_ptr<Controller> m_controller_ptr;
public:
	WaitingForPlayer(std::shared_ptr<Controller>);
	void makeAction() override;
};