project(firsttest)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/level1_bg.h
        src/level1_bg.c
        src/level1_scene.h
        src/level1_scene.cpp)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )