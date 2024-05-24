CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(MSGame)

ADD_SUBDIRECTORY(googletest)


ADD_EXECUTABLE(run
    src/main.cpp
    src/game.cpp
    src/item.cpp
    src/player.cpp
    src/monster.cpp
)

ADD_EXECUTABLE(test
    tests/test.cpp
)

TARGET_LINK_LIBRARIES(test gtest gmock gtest_main)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)