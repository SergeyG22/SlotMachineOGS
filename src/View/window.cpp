#include "../../include/View/window.h"

sf::RenderWindow* Window::getWindowPtr() {
	return &m_window;
}

void Window::render() {
	m_window.clear();
//	m_window.draw();
	m_window.display();
	Display::render();
}

bool Window::isOpen() const {
	return m_window.isOpen();
}
