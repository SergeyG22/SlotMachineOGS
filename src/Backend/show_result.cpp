#include "Backend/show_result.h"

extern int CURRENT_STATE;
extern int PREVIOUS_STATE;


ShowResult::ShowResult(GraphicObjects& graphic_objects, std::shared_ptr<Display>& display_ptr, std::shared_ptr<Controller>& controller):m_graphic_objects(graphic_objects), m_display_ptr(display_ptr), m_controller_ptr(controller) {
	m_graphic_objects.winner_logo->getSprite()->setColor(sf::Color(255, 255, 255, 0.0));
}

void ShowResult::makeAction() {

	resetSettings();

	m_display_ptr->getWindowPtr()->draw(*(m_graphic_objects.winner_logo->getSprite()));
	m_booster += m_boost_step;

	if (m_booster >= TOTAL_FLICKER_TIME) {
		m_boost_step = -m_boost_step;
	}
	if ((m_booster < 0)  && (m_flickers_counter < (NUMBER_OF_FLICKERS))) {
		m_flickers_counter++;
		m_alpha = 0.0;
		m_booster = 0;
		m_boost_step = 2.5;
		if (m_flickers_counter == NUMBER_OF_FLICKERS) {
			m_flickers_counter = 0;
			CURRENT_STATE = 0;
		}
	}
	if ((m_booster >= 0) && (m_booster <= 255)) {
		m_alpha = m_booster;
	}

	m_graphic_objects.winner_logo->getSprite()->setColor(sf::Color(255, 255, 255, m_alpha));
	m_controller_ptr->eventLoop();
}

void ShowResult::resetSettings() {
	if (PREVIOUS_STATE) {
		m_graphic_objects.winner_logo->getSprite()->setColor(sf::Color(255, 255, 255, 0.0));
		m_flickers_counter = 0;
		m_alpha = 0.0;
		m_booster = 0;
		m_boost_step = 2.5;
		PREVIOUS_STATE = 0;
	}
}