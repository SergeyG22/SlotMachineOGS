#include "../../include/Controller/pk_controller.h"

PkController::PkController(std::shared_ptr<Display>window_ptr):m_window_ptr(window_ptr) {

}

void PkController::eventLoop() {
	sf::Event event;
	
	while (m_window_ptr->getWindowPtr()->waitEvent(event)) {

		if (event.type == sf::Event::Closed) {
			m_window_ptr->getWindowPtr()->close();
		}
		mouseEvent(event);
		keyboardEvent(event);
	}

}

bool PkController::mouseEvent(const sf::Event& event) {

	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.key.code == sf::Mouse::Left) {
			std::cout << "Mouse pressed\n";
		}
	}

	return false;
}

bool PkController::keyboardEvent(const sf::Event& event) {

	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {

		case sf::Keyboard::Key::W:{
			std::cout << "W\n";
			break;
			}

		}
	}

	return false;
}