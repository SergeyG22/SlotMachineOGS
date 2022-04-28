#pragma once

class StateMachine {

public:
	virtual ~StateMachine() = default;
	virtual void makeAction() = 0;
};

