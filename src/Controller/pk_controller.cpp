#include "../../include/Controller/pk_controller.h"

PkController::PkController(std::shared_ptr<Display>window_ptr, std::vector<Spin>& rollers, std::shared_ptr<Timer>& timer):m_window_ptr(window_ptr), m_rollers(rollers), m_timer_ptr(timer) {

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

		case sf::Keyboard::Key::P:{

			if (std::all_of(m_rollers.begin(), m_rollers.end(), [](Spin& value) {  return value.getSpinState() == false; })) {
				std::for_each(m_rollers.begin(), m_rollers.end(), [](Spin& spin) { spin.setSpinState(true); });
				m_timer_ptr->start();
			}

			break;
			}

		case sf::Keyboard::Key::Space: { 

			if (std::all_of(m_rollers.begin(), m_rollers.end(), [](Spin& value) {  return value.getStateSpeedDownMode() == false; })) {
				if (std::any_of(m_rollers.begin(), m_rollers.end(), [](Spin& value) {  return value.getSpinState() == true; })) {
					std::for_each(m_rollers.begin(), m_rollers.end(), [](Spin& spin) { spin.maxBoostReached();
																					   spin.speedDownMode();																					   
						});
					m_timer_ptr->stop();
				}
			}

			break;
		}

		}
	}

	return false;
}