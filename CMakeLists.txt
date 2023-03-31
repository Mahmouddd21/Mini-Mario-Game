cmake_minimum_required(VERSION 3.23)
project(Game2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Game2 ../Game2/main.cpp ../Game2/Champion.cpp ../Game2/Champion.h ../Game2/Map.cpp ../Game2/Map.h ../Game2/Cell.cpp ../Game2/Cell.h ../Game2/Obstacle.cpp ../Game2/Obstacle.h ../Game2/Bomb.cpp ../Game2/Bomb.h ../Game2/Thief.cpp ../Game2/Thief.h ../Game2/Gem.cpp ../Game2/Gem.h ../Game2/Coin.cpp ../Game2/Coin.h ../Game2/Potion.cpp ../Game2/Potion.h ../Game2/Mario.cpp ../Game2/Mario.h ../Game2/Luigi.cpp ../Game2/Luigi.h)
