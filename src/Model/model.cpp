#include "Model/model.h"

const std::vector<std::vector<int>>& Model::getModel() {
	return m_model;
}

Model::Model() {
	int width_counter = 0;
	while (width_counter <= MODEL_WIDTH - 1) {
		std::random_device device;
		std::mt19937 mt(device());
		std::uniform_int_distribution<std::mt19937::result_type>object(0, MODEL_HEIGHT - 1);
		int random_row_number = object(mt);

		for (int i = 0; i <= MODEL_HEIGHT - 1; ++i) {
			m_model[i][width_counter] = random_row_number;
			random_row_number++;
			if (random_row_number > MODEL_HEIGHT - 1) {
				random_row_number = 0;
			}
		}
		width_counter++;
	}
}
