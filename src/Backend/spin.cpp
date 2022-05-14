#include "Backend/spin.h"

Spin::Spin(std::pair<double, double>speed_values) : m_speed_values(speed_values){
	m_boost_step = getRandomSpeed();
}

void Spin::setSpinState(bool isSpinState) {
	this->m_is_spin = isSpinState;
}

void Spin::maxBoostReached() {
	m_max_boost_reached = true;
	setStopBoostValue();
}

void Spin::setStopBoostValue() {
	m_boost = STOP_BOOST_VALUE;
}

bool Spin::getSpinState() const {
	return m_is_spin;
}

void Spin::setFrameStartPosition(int pos) {
	m_offset = pos;
}

bool Spin::speedUpMode() {
	if (m_boost >= MAX_BOOST) {    
		m_max_boost_reached = true;
		return true;
	}
	return false;
}

void Spin::speedDownMode() {   
	m_boost_step = -m_boost_step;
	m_speed_down_mode_is_enabled = true;
}

bool Spin::getStateSpeedDownMode() const {
	return m_speed_down_mode_is_enabled;
}

void Spin::resetAllValues() {
	m_boost = 0.0;
	m_is_spin = false;
	m_get_random_speed = true;
	m_max_boost_reached = false;
	m_speed_down_mode_is_enabled = false;
}

void Spin::checkInputFrame() {

	if (((int)m_boost == STABLE_SPEED_VALUE) && m_max_boost_reached) {
		m_boost = STABLE_SPEED_VALUE;
	switch (m_offset) {

		case FRAME_HEIGHT * 1: {   
			resetAllValues();
			break;
		}
		case FRAME_HEIGHT * 2: {  
			resetAllValues();
			break;
		}
		case FRAME_HEIGHT * 3: {   
			resetAllValues();
			break;
		}
		case FRAME_HEIGHT * 4: {  
			resetAllValues();
			break;
		}
	   }	
	}
	else {
		m_boost += m_boost_step;
	}
}

double Spin::getRandomSpeed() const {
	std::random_device device;
	std::mt19937 mt(device());
	std::uniform_real_distribution<double>object(m_speed_values.first, m_speed_values.second);
	return object(mt);
}

int Spin::spinObject(const std::unique_ptr<RenderingElement>& roller, sf::RenderWindow& m_window, std::pair<std::shared_ptr<Timer>, std::shared_ptr<Timer>>& timer) {
	if (m_is_spin) {
		m_offset += m_boost;
	    
		checkInputFrame();

		if (speedUpMode()) { 
			if (timer.first->elapsedSeconds() > TIME_TO_STOP) {
				maxBoostReached();
				speedDownMode();
				timer.first->stop();
			}
		}

		if (m_offset > FRAME_HEIGHT * MODEL_HEIGHT) {
			m_offset = 0;
		}

		if (m_get_random_speed) {
			m_boost_step = getRandomSpeed();
			m_get_random_speed = false;
		}

		return m_offset;
	}
	return m_offset;
};

