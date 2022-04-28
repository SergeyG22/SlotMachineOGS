#pragma once
#include <SFML/Graphics.hpp>
#include "../../include/Model/model.h"
#include <iostream>
#include "../../include/Backend/timer.h"
#include "../../include/Backend/state_machine.h"

class Display {

public:
	virtual ~Display() = default;
	virtual sf::RenderWindow* getWindowPtr() = 0;
	virtual void render(const std::shared_ptr<Model>&, std::pair<std::shared_ptr<Timer>, std::shared_ptr<Timer>>&, std::vector<std::shared_ptr<StateMachine>>&);
	virtual bool isOpen() const = 0;
};
