#include "../../include/Controller/pk_controller.h"

extern int CURRENT_STATE;
extern int PREVIOUS_STATE;

PkController::PkController(std::shared_ptr<Display>window_ptr, std::vector<Spin>& rollers, std::pair<std::shared_ptr<Timer>, std::shared_ptr<Timer>>& timer, const GraphicObjects& graphic_objects) :m_window_ptr(window_ptr), m_rollers(rollers),
																																																	 m_timer_ptr(timer), m_graphic_objects_ptr(graphic_objects) {
}

void PkController::eventLoop() {
	sf::Event event;

	sf::Vector2i global_mouse_position = sf::Mouse::getPosition(*(m_window_ptr->getWindowPtr()));
	sf::Vector2f view_mouse_position = m_window_ptr->getWindowPtr()->mapPixelToCoords(global_mouse_position);

	while (m_window_ptr->getWindowPtr()->pollEvent(event)) {
	
		if (event.type == sf::Event::Closed) {
			m_window_ptr->getWindowPtr()->close();
		}
		mouseEvent(event, view_mouse_position);
		keyboardEvent(event);
	}

}

bool PkController::mouseEvent(const sf::Event& event, const sf::Vector2f& view_mouse_position) {

	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.key.code == sf::Mouse::Left) {		
			if (m_graphic_objects_ptr.button_start->getSprite()->getGlobalBounds().contains(view_mouse_position.x, view_mouse_position.y)) {
				CURRENT_STATE = 1;
				PREVIOUS_STATE = 1;
				return true;
			}

			if (m_timer_ptr.second->elapsedSeconds() > TIME_FROM_START_ALLOWS_PLAYER_TO_PRESS_STOP_BUTTON) {

				if (m_graphic_objects_ptr.button_stop->getSprite()->getGlobalBounds().contains(view_mouse_position.x, view_mouse_position.y)) {
					
					if (std::all_of(m_rollers.begin(), m_rollers.end(), [](Spin& value) {  return value.getStateSpeedDownMode() == false; })) {
						
						if (std::any_of(m_rollers.begin(), m_rollers.end(), [](Spin& value) {  return value.getSpinState() == true; })) {
							std::for_each(m_rollers.begin(), m_rollers.end(), [](Spin& spin) { spin.maxBoostReached();
																							   spin.speedDownMode();
								});
							m_timer_ptr.first->stop();
							m_timer_ptr.second->stop();
							return true;
						}
						
					}
				}
			}
		}
	}

	if (m_graphic_objects_ptr.button_start->getSprite()->getGlobalBounds().contains(view_mouse_position.x, view_mouse_position.y)) {
		m_graphic_objects_ptr.button_start->getSprite()->setColor(sf::Color(246, 246, 229, 200.0));
	}
	else {
		m_graphic_objects_ptr.button_start->getSprite()->setColor(sf::Color::White);
	}

	if (m_graphic_objects_ptr.button_stop->getSprite()->getGlobalBounds().contains(view_mouse_position.x, view_mouse_position.y)) {
		m_graphic_objects_ptr.button_stop->getSprite()->setColor(sf::Color(246, 246, 229, 200.0));
	}
	else {
		m_graphic_objects_ptr.button_stop->getSprite()->setColor(sf::Color::White);
	}


	return false;
}

bool PkController::keyboardEvent(const sf::Event& event) {

	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {

		case sf::Keyboard::Key::R:{
			CURRENT_STATE = 1;
			PREVIOUS_STATE = 1;
			break;
			}

		case sf::Keyboard::Key::Space: { 

			if (m_timer_ptr.second->elapsedSeconds() > TIME_FROM_START_ALLOWS_PLAYER_TO_PRESS_STOP_BUTTON) {
				
				if (std::all_of(m_rollers.begin(), m_rollers.end(), [](Spin& value) {  return value.getStateSpeedDownMode() == false; })) {
					if (std::any_of(m_rollers.begin(), m_rollers.end(), [](Spin& value) {  return value.getSpinState() == true; })) {
						std::for_each(m_rollers.begin(), m_rollers.end(), [](Spin& spin) { spin.maxBoostReached();
						spin.speedDownMode();
							});
						m_timer_ptr.first->stop();
						m_timer_ptr.second->stop();
						break;
					}
				}
				
			}
			break;
		}

		}
	}

	return false;
}