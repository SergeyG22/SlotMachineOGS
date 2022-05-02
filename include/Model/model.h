#pragma once
#include <vector>
#include "../config.h"
#include <random>
#include <chrono>
#include <iostream>

class Model {
	std::vector<std::vector<int>> m_model { MODEL_HEIGHT, std::vector<int>(MODEL_WIDTH, 0) };
public:
	const std::vector<std::vector<int>>& getModel();
	Model();
};


