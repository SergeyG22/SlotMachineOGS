#include "Graphics/graphic_objects.h"

GraphicObjects::GraphicObjects() {
	roller_a = std::make_unique<RenderingElement>("rollers/roller_type_a.jpg");
	roller_a->getSprite()->setPosition(ROLLER_A_POS_X, ROLLER_A_POS_Y);
	roller_b = std::make_unique<RenderingElement>("rollers/roller_type_a.jpg");
	roller_b->getSprite()->setPosition(ROLLER_B_POS_X, ROLLER_B_POS_Y);
	roller_c = std::make_unique<RenderingElement>("rollers/roller_type_a.jpg");
	roller_c->getSprite()->setPosition(ROLLER_C_POS_X, ROLLER_C_POS_Y);
	roller_d = std::make_unique<RenderingElement>("rollers/roller_type_a.jpg");
	roller_d->getSprite()->setPosition(ROLLER_D_POS_X, ROLLER_D_POS_Y);
	roller_e = std::make_unique<RenderingElement>("rollers/roller_type_a.jpg");
	roller_e->getSprite()->setPosition(ROLLER_E_POS_X, ROLLER_E_POS_Y);

	button_start = std::make_unique<RenderingElement>("buttons/start_button.png");
	button_start->getSprite()->setPosition(START_BUTTON_POS_X, START_BUTTON_POS_Y);
	button_stop = std::make_unique<RenderingElement>("buttons/stop_button.png");
	button_stop->getSprite()->setPosition(STOP_BUTTON_POS_X, STOP_BUTTON_POS_Y);

	winner_logo = std::make_unique<RenderingElement>("logo/winner_logo.png");
	winner_logo->getSprite()->setPosition(WINNER_LOGO_POS_X, WINNER_LOGO_POS_Y);

	scoreboard = std::make_unique<RenderingElement>("logo/scoreboard.png");
	scoreboard->getSprite()->setPosition(SCOREBOARD_POS_X, SCOREBOARD_POS_Y);

	main_screen = std::make_unique<RenderingElement>("screens/screen_type_a.jpg");
}
