#include "../../include/Controller/pk_controller.h"

PkController::PkController(std::shared_ptr<Display>window_ptr):m_window_ptr(window_ptr) {

}

void PkController::eventLoop() {
	sf::Event event;
	
	while (m_window_ptr->getWindowPtr()->pollEvent(event)) {

		if (event.type == sf::Event::Closed) {
			m_window_ptr->getWindowPtr()->close();
		}
	}
}
