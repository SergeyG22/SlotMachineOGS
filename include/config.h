#pragma once

constexpr unsigned int WINDOW_WIDTH = 1280;
constexpr unsigned int WINDOW_HEIGHT = 1024;
constexpr int MODEL_WIDTH = 5;
constexpr int MODEL_HEIGHT = 4;

const int FRAME_WIDTH = 200;
const int FRAME_HEIGHT = 200;

const double ROLLER_A_MAX_SPEED = 0.12;
const double ROLLER_B_MAX_SPEED = 0.1;
const double ROLLER_C_MAX_SPEED = 0.08;
const double ROLLER_D_MAX_SPEED = 0.06;
const double ROLLER_E_MAX_SPEED = 0.04;

const double ROLLER_A_MIN_SPEED = 0.11;
const double ROLLER_B_MIN_SPEED = 0.09;
const double ROLLER_C_MIN_SPEED = 0.07;
const double ROLLER_D_MIN_SPEED = 0.05;
const double ROLLER_E_MIN_SPEED = 0.03;

const int STABLE_SPEED_VALUE = 1.5;

const int ROLLER_A_POS_X = 140;
const int ROLLER_A_POS_Y = 285;
const int ROLLER_B_POS_X = ROLLER_A_POS_X + FRAME_WIDTH;
const int ROLLER_B_POS_Y = ROLLER_A_POS_Y;
const int ROLLER_C_POS_X = ROLLER_B_POS_X + FRAME_WIDTH;
const int ROLLER_C_POS_Y = ROLLER_B_POS_Y;
const int ROLLER_D_POS_X = ROLLER_C_POS_X + FRAME_WIDTH;
const int ROLLER_D_POS_Y = ROLLER_C_POS_Y;
const int ROLLER_E_POS_X = ROLLER_D_POS_X + FRAME_WIDTH;
const int ROLLER_E_POS_Y = ROLLER_D_POS_Y;

const int START_BUTTON_POS_X = 305;
const int START_BUTTON_POS_Y = 575;
const int STOP_BUTTON_POS_X = 655;
const int STOP_BUTTON_POS_Y = 575;

const int WINNER_LOGO_POS_X = 335;
const int WINNER_LOGO_POS_Y = 50;

const int ROW_NUMBER = 1;
const int MAX_BOOST = 50;
const int STOP_BOOST_VALUE = 20;

const int TIME_TO_STOP = 8;
const int TIME_FROM_START_ALLOWS_PLAYER_TO_PRESS_STOP_BUTTON = 4;

const int FPS = 60.0;
const float VALUE_OF_SCREEN_RATE = 520.f;



