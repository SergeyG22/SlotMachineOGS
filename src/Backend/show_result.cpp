#include "../../include/Backend/show_result.h"

ShowResult::ShowResult(GraphicObjects& graphic_objects, std::shared_ptr<Display>& display_ptr, std::shared_ptr<Controller>& controller):m_graphic_objects(graphic_objects), m_display_ptr(display_ptr), m_controller_ptr(controller) {

}

void ShowResult::makeAction() {
	m_display_ptr->getWindowPtr()->draw(*(m_graphic_objects.winner_logo->getSprite()));
	m_value += m_boost_step;

	if (m_value >= 400) {
		m_boost_step = -m_boost_step;
	}
	if (m_value < 0) {
	   // m_boost = 0;
		std::cout << "GAME OVER!\n";
	}
	if (m_value > 0 && m_value <= 255) {
		m_boost = m_value;
	}


	m_graphic_objects.winner_logo->getSprite()->setColor(sf::Color(255, 255, 255, m_boost));
	m_controller_ptr->eventLoop();
}
