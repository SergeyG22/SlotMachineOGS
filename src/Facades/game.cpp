#include "../../include/Facades/game.h"

Game::Game() {
	m_display_ptr = std::make_unique<Window>();
	m_controller_ptr = std::make_unique<PkController>(m_display_ptr);
}

void Game::gameLoop() {
	while (m_display_ptr->isOpen()) {
		m_display_ptr->render();
		m_controller_ptr->eventLoop();
	}
}
