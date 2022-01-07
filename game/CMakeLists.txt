project(firsttest)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/level1_scene.h
        src/level1_scene.cpp
        src/background.h
        src/background.c
        src/farmer.h
        src/farmer.c
        src/shared.h
        src/shared.c)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )