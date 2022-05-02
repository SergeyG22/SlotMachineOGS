#pragma once
#include "../../include/Backend/state_machine.h"
#include "../../include/Backend/waiting_player.h"
#include "../../include/Backend/spining_slots.h"
#include "../../include/Backend/show_result.h"
#include <iostream>

class StateContext {
	std::shared_ptr<StateMachine> m_state_machine_ptr;
public:
	StateContext();
	void setAction(std::shared_ptr<StateMachine>);
	void makeAction();
};