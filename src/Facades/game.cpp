#include "../../include/Facades/game.h"

Game::Game() {

	m_display_ptr = std::make_unique<Window>(m_rollers, m_graphic_objects);
	m_model_ptr = std::make_unique<Model>();
	m_controller_ptr = std::make_unique<PkController>(m_display_ptr, m_rollers);

	const int ROLLER_A_START_POSITION_Y = FRAME_WIDTH * m_model_ptr->getModel()[1][0];
	const int ROLLER_B_START_POSITION_Y = FRAME_WIDTH * m_model_ptr->getModel()[1][1];
	const int ROLLER_C_START_POSITION_Y = FRAME_WIDTH * m_model_ptr->getModel()[1][2];
	const int ROLLER_D_START_POSITION_Y = FRAME_WIDTH * m_model_ptr->getModel()[1][3];
	const int ROLLER_E_START_POSITION_Y = FRAME_WIDTH * m_model_ptr->getModel()[1][4];

	m_graphic_objects.roller_a->getSprite()->setTextureRect(sf::IntRect(0, ROLLER_A_START_POSITION_Y, FRAME_WIDTH, FRAME_HEIGHT));
	m_graphic_objects.roller_b->getSprite()->setTextureRect(sf::IntRect(0, ROLLER_B_START_POSITION_Y, FRAME_WIDTH, FRAME_HEIGHT));
	m_graphic_objects.roller_c->getSprite()->setTextureRect(sf::IntRect(0, ROLLER_C_START_POSITION_Y, FRAME_WIDTH, FRAME_HEIGHT));
	m_graphic_objects.roller_d->getSprite()->setTextureRect(sf::IntRect(0, ROLLER_D_START_POSITION_Y, FRAME_WIDTH, FRAME_HEIGHT));
	m_graphic_objects.roller_e->getSprite()->setTextureRect(sf::IntRect(0, ROLLER_E_START_POSITION_Y, FRAME_WIDTH, FRAME_HEIGHT));

	m_rollers[0].setStartPosition(ROLLER_A_START_POSITION_Y);
	m_rollers[1].setStartPosition(ROLLER_B_START_POSITION_Y);
	m_rollers[2].setStartPosition(ROLLER_C_START_POSITION_Y);
	m_rollers[3].setStartPosition(ROLLER_D_START_POSITION_Y);
	m_rollers[4].setStartPosition(ROLLER_E_START_POSITION_Y);
}

void Game::gameLoop() {
	while (m_display_ptr->isOpen()) {
		m_display_ptr->render(m_model_ptr);
		m_controller_ptr->eventLoop();
	}
}

