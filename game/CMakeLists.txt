project(firsttest)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/test_scene.cpp
        src/test_scene.h
        src/test.c
        src/test.h
        src/testbackground.c
        src/testbackground.h
        src/lama.c
        src/lama.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )