#pragma once
#include <vector>
#include "../config.h"
#include <random>
#include <chrono>
#include <iostream>

class Model {
	std::vector<std::vector<int>>m_model { MODEL_HEIGHT, std::vector<int>(MODEL_WIDTH, 0) };
public:
	const std::vector<std::vector<int>>& getModel();
	Model();
};


//пять барабанов по четыре символа
//[0][0][0][0][0]
//[1][1][1][1][1]
//[2][2][2][2][2]
//[3][3][3][3][3]