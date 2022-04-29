#include "../../include/Backend/spining_slots.h"

extern int CURRENT_STATE;

SpiningSlots::SpiningSlots(std::vector<Spin>& rollers, std::pair<std::shared_ptr<Timer>, std::shared_ptr<Timer>>& timer, GraphicObjects& graphic_objects, std::shared_ptr<Display>& display_ptr, std::shared_ptr<Controller>& controller):
												m_rollers(rollers), m_timer_ptr(timer), m_graphic_objects(graphic_objects),
												m_display_ptr(display_ptr), m_controller_ptr(controller){
}

void SpiningSlots::makeAction() {

	m_controller_ptr->eventLoop();

	int offset_a = m_rollers[0].spinObject(m_graphic_objects.roller_a, *(m_display_ptr->getWindowPtr()), m_timer_ptr);
	(m_graphic_objects).roller_a->getSprite()->setTextureRect(sf::IntRect(0,(0) + offset_a, FRAME_WIDTH, FRAME_HEIGHT) );

	int offset_b = m_rollers[1].spinObject(m_graphic_objects.roller_b, *(m_display_ptr->getWindowPtr()), m_timer_ptr);
	(m_graphic_objects).roller_b->getSprite()->setTextureRect(sf::IntRect(0, (0) + offset_b, FRAME_WIDTH, FRAME_HEIGHT));

	int offset_c = m_rollers[2].spinObject(m_graphic_objects.roller_c, *(m_display_ptr->getWindowPtr()), m_timer_ptr);
	(m_graphic_objects).roller_c->getSprite()->setTextureRect(sf::IntRect(0, (0) + offset_c, FRAME_WIDTH, FRAME_HEIGHT));

	int offset_d = m_rollers[3].spinObject(m_graphic_objects.roller_d, *(m_display_ptr->getWindowPtr()), m_timer_ptr);
	(m_graphic_objects).roller_d->getSprite()->setTextureRect(sf::IntRect(0, (0) + offset_d, FRAME_WIDTH, FRAME_HEIGHT));

	int offset_e = m_rollers[4].spinObject(m_graphic_objects.roller_e, *(m_display_ptr->getWindowPtr()), m_timer_ptr);
	(m_graphic_objects).roller_e->getSprite()->setTextureRect(sf::IntRect(0, (0) + offset_e, FRAME_WIDTH, FRAME_HEIGHT));

	if (m_spin_rollers) {
		std::for_each(m_rollers.begin(), m_rollers.end(), [](Spin& spin) { spin.setSpinState(true); });
		m_timer_ptr.first->start();
		m_timer_ptr.second->start();
		m_spin_rollers = false;
	}

	if (m_timer_ptr.second->elapsedSeconds() > TIME_FROM_START_ALLOWS_PLAYER_TO_PRESS_STOP_BUTTON) { 
			
			if (std::all_of(m_rollers.begin(), m_rollers.end(), [](Spin& value) {  return value.getStateSpeedDownMode() == false; })) {

				if (std::any_of(m_rollers.begin(), m_rollers.end(), [](Spin& value) {  return value.getSpinState() == true; })) {
					std::for_each(m_rollers.begin(), m_rollers.end(), [](Spin& spin) { spin.maxBoostReached();
																					   spin.speedDownMode();
						});
					m_timer_ptr.first->stop();
					m_timer_ptr.second->stop();
				}

			}
			
	}
	if (std::all_of(m_rollers.begin(), m_rollers.end(), [](Spin& value) {  return value.getSpinState() == false; })) {
		CURRENT_STATE = 2;
		m_spin_rollers = true;
	} 
	
}
