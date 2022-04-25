#include "../../include/Controller/pk_controller.h"

PkController::PkController(std::shared_ptr<Display>window_ptr, std::vector<Spin>& rollers):m_window_ptr(window_ptr), m_rollers(rollers) {

}

void PkController::eventLoop() {
	sf::Event event;
	
	while (m_window_ptr->getWindowPtr()->pollEvent(event)) {

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

		case sf::Keyboard::Key::Space:{

			if (std::all_of(m_rollers.begin(), m_rollers.end(), [](Spin value) {  return value.getSpintState() == false; })) {
				for (int i = 0; i < m_rollers.size(); ++i) {
					m_rollers[i].setSpinState(true);
				}
			}

			break;
			}

		}
	}

	return false;
}