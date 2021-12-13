project(firsttest)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/test_scene.cpp
        src/test_scene.h
        src/lama.h
        src/test.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )