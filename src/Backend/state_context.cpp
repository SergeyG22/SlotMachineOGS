#include "Backend/state_context.h"

StateContext::StateContext() {

}

void StateContext::setAction(std::shared_ptr<StateMachine>action) {
	m_state_machine_ptr = action;
}

void StateContext::makeAction() {
	m_state_machine_ptr->makeAction();
}
