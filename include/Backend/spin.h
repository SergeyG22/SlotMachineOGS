#pragma once
#include <SFML/Graphics.hpp>
#include "../Graphics/rendering_element.h"
#include "../config.h"

class Spin {
	int m_offset = 0;
	double m_boost = 0.0;
	double m_boostStep;
	bool m_isSpin = false;
	bool m_stable_speed_check = false;
	int m_stable_speed_value = 5;
	void resetValues();
	void checkingInputFrame();
public:
	void spinCylinder(const std::unique_ptr<RenderingElement>& roller, sf::RenderWindow& m_window);
	void setSpinState(bool isSpinState);
	bool getSpintState() const;
	void setStartPosition(int);
	Spin(double);
};