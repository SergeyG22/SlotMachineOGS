#include "../../include/Backend/waiting_player.h"

WaitingForPlayer::WaitingForPlayer(std::shared_ptr<Controller> controller): m_controller_ptr(controller) {

}

void WaitingForPlayer::makeAction() {
	m_controller_ptr->eventLoop();
}
