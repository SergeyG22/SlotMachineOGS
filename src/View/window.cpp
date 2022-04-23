#include "../../include/View/window.h"

sf::RenderWindow* Window::getWindowPtr() {
	return &m_window;
}

void Window::render(const std::shared_ptr<Model>& model) {
	m_window.clear();
//	m_window.draw();
	m_window.display();
	Display::render(model);
}

bool Window::isOpen() const {
	return m_window.isOpen();
}
