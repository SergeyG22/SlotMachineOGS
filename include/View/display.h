#pragma once
#include <SFML/Graphics.hpp>
#include "../../include/Model/model.h"
#include <iostream>

class Display {

public:
	virtual ~Display() = default;
	virtual sf::RenderWindow* getWindowPtr() = 0;
	virtual void render(const std::shared_ptr<Model>&);
	virtual bool isOpen() const = 0;
};
