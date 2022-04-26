#include "../../include/View/window.h"

sf::RenderWindow* Window::getWindowPtr() {
	return &m_window;
}

Window::Window(std::vector<Spin>&rollers, GraphicObjects& graphic_objects) : m_rollers(rollers), m_graphic_objects(graphic_objects) {
	
}

void Window::render(const std::shared_ptr<Model>& model) {  

	m_window.clear();
	m_rollers[0].spinObject(m_graphic_objects.roller_a, m_window);
	m_rollers[1].spinObject(m_graphic_objects.roller_b, m_window);
	m_rollers[2].spinObject(m_graphic_objects.roller_c, m_window);
	m_rollers[3].spinObject(m_graphic_objects.roller_d, m_window);
	m_rollers[4].spinObject(m_graphic_objects.roller_e, m_window);

	m_window.display();
	Display::render(model);
}

bool Window::isOpen() const {
	return m_window.isOpen();
}

