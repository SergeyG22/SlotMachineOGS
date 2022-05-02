#pragma once
#include <SFML/Graphics.hpp>
#include "../Graphics/rendering_element.h"
#include "../config.h"
#include <random>
#include <chrono>
#include "../Backend/timer.h"

class Spin {
	int m_offset = 0;
	double m_boost = 0.0;
	double m_boost_step = 0.0;
	bool m_is_spin = false;
	bool m_get_random_speed = false;
	bool m_max_boost_reached = false;
	bool m_speed_down_mode_is_enabled = false;
	std::pair<double, double> m_speed_values;
	void setStopBoostValue();
	void resetAllValues();
	void checkInputFrame();
	double getRandomSpeed() const;
public:
	int spinObject(const std::unique_ptr<RenderingElement>& roller, sf::RenderWindow& m_window, std::pair<std::shared_ptr<Timer>, std::shared_ptr<Timer>>&m_timer_ptr);
	bool speedUpMode();
	void speedDownMode();
	void maxBoostReached();
	void setSpinState(bool);
	bool getSpinState() const;
	void setFrameStartPosition(int);
	bool getStateSpeedDownMode() const;
	Spin(std::pair<double,double>);
};