project(FarmCity)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/Farm1Scene.h
        src/Farm1Scene.cpp
        src/background.h
        src/background.c
        src/farmer.h
        src/farmer.c)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )