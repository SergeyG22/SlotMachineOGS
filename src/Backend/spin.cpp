#include "../../include/Backend/spin.h"

Spin::Spin(double boostStep) :m_boostStep(boostStep) {

};

void Spin::setSpinState(bool isSpinState) {
	this->m_isSpin = isSpinState;
}

bool Spin::getSpintState() const {
	return m_isSpin;
}

void Spin::setStartPosition(int pos) {
	m_offset = pos;
}


void Spin::resetValues() {
	m_isSpin = false;
	m_stable_speed_check = false;
	m_boost = 0;
}

void Spin::checkingInputFrame() {

	if (((int)m_boost == m_stable_speed_value) && m_stable_speed_check) {
		m_boost = m_stable_speed_value;
		switch (m_offset) {

		case FRAME_HEIGHT * 0: {
			resetValues();
			m_offset = FRAME_HEIGHT * 0;
			break;
		}
		case FRAME_HEIGHT * 1: {
			resetValues();
			m_offset = FRAME_HEIGHT * 1;
			break;
		}
		case FRAME_HEIGHT * 2: {
			resetValues();
			m_offset = FRAME_HEIGHT * 2;
			break;
		}
		case FRAME_HEIGHT * 3: {
			resetValues();
			m_offset = FRAME_HEIGHT * 3;
			break;
		}
		case FRAME_HEIGHT * 4: {
			resetValues();
			m_offset = FRAME_HEIGHT * 4;
			break;
		}
		}
	}
	else {
		m_boost += m_boostStep;
	}
}

void Spin::spinCylinder(const std::unique_ptr<RenderingElement>& roller, sf::RenderWindow& m_window) {
	if (m_isSpin) {
		m_offset += m_boost;

		checkingInputFrame();

		if (m_boost >= MAX_BOOST) {
			m_boostStep = -m_boostStep;
			m_stable_speed_check = true;
		}
		if (m_boost <= 0) {
			m_boostStep = -m_boostStep;
			m_isSpin = false;
		}
		if (m_offset > FRAME_HEIGHT * MODEL_HEIGHT) {
			m_offset = 0;
		}
		roller->getSprite()->setTextureRect(sf::IntRect(0, (0) + m_offset, FRAME_WIDTH, FRAME_HEIGHT));
	}
	m_window.draw(*(roller->getSprite()));
};
