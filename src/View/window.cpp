#include "../../include/View/window.h"

extern int CURRENT_STATE;

sf::RenderWindow* Window::getWindowPtr() {
	return &m_window;
}

Window::Window(std::vector<Spin>&rollers, GraphicObjects& graphic_objects) : m_rollers(rollers), m_graphic_objects(graphic_objects) {

}

void Window::render(const std::shared_ptr<Model>& model, std::pair<std::shared_ptr<Timer>, std::shared_ptr<Timer>>& timer, std::vector<std::shared_ptr<StateMachine>>& context) {
	
	
	m_window.clear();

	m_window.draw(*(m_graphic_objects.main_screen->getSprite()));
	context[CURRENT_STATE]->makeAction();

    m_window.draw(*(m_graphic_objects).roller_a->getSprite());
	m_window.draw(*(m_graphic_objects).roller_b->getSprite());
	m_window.draw(*(m_graphic_objects).roller_c->getSprite());
	m_window.draw(*(m_graphic_objects).roller_d->getSprite());
	m_window.draw(*(m_graphic_objects).roller_e->getSprite());

	m_window.draw(*(m_graphic_objects.button_start->getSprite()));
	m_window.draw(*(m_graphic_objects.button_stop->getSprite()));
	m_window.draw(*(m_graphic_objects.scoreboard->getSprite()));

	m_window.display();

	Display::render(model, timer, context);

	sf::Int32 frame_duration = clock.getElapsedTime().asMilliseconds();
	sf::Int32 time_to_sleep = int(VALUE_OF_SCREEN_RATE / FPS) - frame_duration; 
	if (time_to_sleep > 0) {
		sf::sleep(sf::milliseconds(time_to_sleep));
	}
	clock.restart();
}

bool Window::isOpen() const {
	return m_window.isOpen();
}

