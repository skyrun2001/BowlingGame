cmake_minimum_required(VERSION 3.23)
project(BowlingGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(BowlingGame main.cpp Game.h Frame.h Output.h)
