add_library(PrivateLibrary STATIC rng.cpp combinations.cpp sminigames.cpp bminigames.cpp wheel.cpp)
target_include_directories(PrivateLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../public)