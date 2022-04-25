#pragma once

constexpr unsigned int WINDOW_WIDTH = 1280;
constexpr unsigned int WINDOW_HEIGHT = 1024;
constexpr int MODEL_WIDTH = 5;
constexpr int MODEL_HEIGHT = 4;

const int FRAME_WIDTH = 200;
const int FRAME_HEIGHT = 200;

const double ROLLER_A_SPEED = 0.1; 
const double ROLLER_B_SPEED = 0.08; 
const double ROLLER_C_SPEED = 0.07; 
const double ROLLER_D_SPEED = 0.05; 
const double ROLLER_E_SPEED = 0.04; 

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

const int ROW_NUMBER = 2;
const int MAX_BOOST = 30;

