#include "../../include/View/window.h"

sf::RenderWindow* Window::getWindowPtr() {
	return &m_window;
}

void Window::render(const std::shared_ptr<Model>& model) {
    													
	m_graphic_objects.roller_a->getSprite()->setTextureRect(sf::IntRect(0, (model->getModel()[ROW_NUMBER][0] * FRAME_HEIGHT), FRAME_WIDTH, FRAME_HEIGHT));
	m_graphic_objects.roller_b->getSprite()->setTextureRect(sf::IntRect(0, (model->getModel()[ROW_NUMBER][1] * FRAME_HEIGHT), FRAME_WIDTH, FRAME_HEIGHT));
	m_graphic_objects.roller_c->getSprite()->setTextureRect(sf::IntRect(0, (model->getModel()[ROW_NUMBER][2] * FRAME_HEIGHT), FRAME_WIDTH, FRAME_HEIGHT));
	m_graphic_objects.roller_d->getSprite()->setTextureRect(sf::IntRect(0, (model->getModel()[ROW_NUMBER][3] * FRAME_HEIGHT), FRAME_WIDTH, FRAME_HEIGHT));
	m_graphic_objects.roller_e->getSprite()->setTextureRect(sf::IntRect(0, (model->getModel()[ROW_NUMBER][4] * FRAME_HEIGHT), FRAME_WIDTH, FRAME_HEIGHT));

	m_window.clear();
	m_window.draw(*(m_graphic_objects.roller_a->getSprite()));
	m_window.draw(*(m_graphic_objects.roller_b->getSprite()));
	m_window.draw(*(m_graphic_objects.roller_c->getSprite()));
	m_window.draw(*(m_graphic_objects.roller_d->getSprite()));
	m_window.draw(*(m_graphic_objects.roller_e->getSprite()));
	m_window.display();

	Display::render(model);
}

bool Window::isOpen() const {
	return m_window.isOpen();
}
