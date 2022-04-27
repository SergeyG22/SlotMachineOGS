#include "../../include/View/display.h"

void Display::render(const std::shared_ptr<Model>& model, std::shared_ptr<Timer>&) {
	for (int i = 0; i < model->getModel().size(); ++i) {
		for (int j = 0; j < model->getModel()[i].size(); ++j) {
//			std::cout << model->getModel()[i][j] << ' ';
		}
//		std::cout << '\n';
	}
//	std::cout << '\n';
//	std::system("cls");
}
