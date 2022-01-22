project(FarmCity)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/scenes/SplashScene.h
        src/scenes/SplashScene.cpp
        src/scenes/Farm1Scene.h
        src/scenes/Farm1Scene.cpp
        src/background.h
        src/background.c
        src/field/field.cpp
        src/field/field.h
        src/field/crops.h
        src/field/crops.cpp
        src/field/crops_data.h
        src/field/crops_data.c
        src/farmer/farmer.h
        src/farmer/farmer.c
        src/farmer/farmer_player.h
        src/farmer/farmer_player.cpp
        src/shared.h
        src/shared.c)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )