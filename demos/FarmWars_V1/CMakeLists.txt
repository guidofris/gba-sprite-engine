project(FarmWars)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/Models/Animal.cpp
        src/Models/Animal.h
        src/Controllers/GameController.h
        src/Controllers/GameController.cpp
        src/Scenes/SelectAnimalScene.cpp
        src/Scenes/SelectAnimalScene.h
        src/Scenes/IntroScene.cpp
        src/Scenes/IntroScene.h
        src/Scenes/MainScene.cpp
        src/Scenes/MainScene.h
        sprites/startscreen.h
        sprites/bg_shared.h
        sprites/bg_shared.c
        sprites/bg_mountain.h
        sprites/bg_mountain.c
        sprites/bg_moon.h
        sprites/bg_moon.c
        sprites/select.h
        sprites/yoda.h
        sprites/lama.h
        sprites/eend.h
        sprites/konijn.h
        sprites/koe.h
        sprites/kip.h
        sprites/shared.h
        src/main.h src/Models/AnimalStats.cpp src/Models/AnimalStats.h src/Models/FarmStats.cpp src/Models/FarmStats.h src/Models/Farm.cpp src/Models/Farm.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
