cmake_minimum_required(VERSION 3.15)
project(kursach_final)

set(CMAKE_CXX_STANDARD 17)

add_executable(kursach_final main.cpp Curl.h Curl.cpp AbstractAPI.h VkAPI.h VkAPI.cpp Abstract_id_list_generator_strategy.h Vk_id_list_generator_strategy.h Vk_id_list_generator_strategy.cpp Crowler.h Crowler.cpp Ok_id_list_generator_strategy.h Ok_id_list_generator_strategy.cpp Facebook_id_list_generator_strategy.h Facebook_id_list_generator_strategy.cpp)