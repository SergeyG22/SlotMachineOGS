#include "../../include/Graphics/graphic_objects.h"

GraphicObjects::GraphicObjects() {
	roller_a = std::make_unique<RenderingElement>("rollers/roller.jpg");
	roller_a->getSprite()->setPosition(ROLLER_A_POS_X, ROLLER_A_POS_Y);
	roller_b = std::make_unique<RenderingElement>("rollers/roller.jpg");
	roller_b->getSprite()->setPosition(ROLLER_B_POS_X, ROLLER_B_POS_Y);
	roller_c = std::make_unique<RenderingElement>("rollers/roller.jpg");
	roller_c->getSprite()->setPosition(ROLLER_C_POS_X, ROLLER_C_POS_Y);
	roller_d = std::make_unique<RenderingElement>("rollers/roller.jpg");
	roller_d->getSprite()->setPosition(ROLLER_D_POS_X, ROLLER_D_POS_Y);
	roller_e = std::make_unique<RenderingElement>("rollers/roller.jpg");
	roller_e->getSprite()->setPosition(ROLLER_E_POS_X, ROLLER_E_POS_Y);
}
