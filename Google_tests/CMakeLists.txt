project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run API_tests.cpp ../API/VkAPI.h ../API/VkAPI.cpp
        ../Id_list_generator_strategy/Vk_id_list_generator_strategy.h
        ../Id_list_generator_strategy/Vk_id_list_generator_strategy.cpp ../API/OkAPI.cpp ../API/OkAPI.h
        ../Id_list_generator_strategy/Ok_id_list_generator_strategy.cpp
        ../Id_list_generator_strategy/Ok_id_list_generator_strategy.h
        ../API/FacebookAPI.cpp ../API/FacebookAPI.h
        ../Id_list_generator_strategy/Facebook_id_list_generator_strategy.cpp
        ../Id_list_generator_strategy/Facebook_id_list_generator_strategy.h
        ../NetService/NetService.h ../NetService/NetService.cpp ../Crowler/Crowler.h ../Crowler/Crowler.cpp ../Id_list_generator_strategy/Ok_id_list_generator_strategy_friends_method.cpp ../Id_list_generator_strategy/Ok_id_list_generator_strategy_friends_method.h
        ../url/url.h ../response/response.h ../response/response.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(Google_Tests_run ${CURL_LIBRARIES})
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})