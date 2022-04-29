#pragma once
#include "../../include/Graphics/rendering_element.h"
#include "../config.h"

class GraphicObjects {

public:
	GraphicObjects();
	std::unique_ptr<RenderingElement>roller_a;
	std::unique_ptr<RenderingElement>roller_b;
	std::unique_ptr<RenderingElement>roller_c;
	std::unique_ptr<RenderingElement>roller_d;
	std::unique_ptr<RenderingElement>roller_e;
	std::unique_ptr<RenderingElement>button_start;
	std::unique_ptr<RenderingElement>button_stop;
	std::unique_ptr<RenderingElement>winner_logo;
	std::unique_ptr<RenderingElement>scoreboard;
	std::unique_ptr<RenderingElement>main_screen;
};
