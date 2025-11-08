# CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(MargonemClone)

# Użyj FetchContent do automatycznego pobierania SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(game MargonemClone.cpp)
target_link_libraries(game sfml-graphics sfml-network sfml-window sfml-system)

# Kopiuj DLL na Windows
if(WIN32)
    add_custom_command(
        TARGET game
        COMMENT "Deploy Qt libraries"
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:sfml-graphics> $<TARGET_FILE_DIR:game>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:sfml-network> $<TARGET_FILE_DIR:game>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:sfml-window> $<TARGET_FILE_DIR:game>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:sfml-system> $<TARGET_FILE_DIR:game>
    )
endif()