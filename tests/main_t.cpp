#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../include/Controller/pk_controller.h"
#include "../include/Backend/timer.h"

TEST(HelloTest, BasicAssertions) {
  std::unique_ptr<Timer>timer = std::make_unique<Timer>();
  timer->start();
  sf::Clock clock;
  EXPECT_EQ(7 * 6, 42);
}