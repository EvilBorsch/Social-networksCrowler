cmake_minimum_required(VERSION 3.15)
project(kursach_final)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(Google_tests)

find_package(Boost COMPONENTS system filesystem thread chrono REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})


add_executable(kursach_final main.cpp NetService/NetService.h NetService/NetService.cpp AbstractClasses/AbstractAPI.h API/VkAPI.h API/VkAPI.cpp AbstractClasses/Abstract_id_list_generator_strategy.h Id_list_generator_strategy/Vk_id_list_generator_strategy.h Id_list_generator_strategy/Vk_id_list_generator_strategy.cpp Crowler/Crowler.h Crowler/Crowler.cpp Id_list_generator_strategy/Ok_id_list_generator_strategy.h Id_list_generator_strategy/Ok_id_list_generator_strategy.cpp Id_list_generator_strategy/Facebook_id_list_generator_strategy.h Id_list_generator_strategy/Facebook_id_list_generator_strategy.cpp API/OkAPI.cpp API/OkAPI.h API/FacebookAPI.cpp API/FacebookAPI.h url/url.h response/response.h response/response.cpp)

target_link_libraries(kursach_final ${Boost_LIBRARIES})

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(kursach_final ${CURL_LIBRARIES})



