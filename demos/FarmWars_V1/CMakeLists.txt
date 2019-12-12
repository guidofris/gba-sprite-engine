project(FarmWars)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/Menu.cpp
        src/Menu.h
        sprites/lama_sprite.h
        src/Game.cpp
        src/Game.h
        src/Base.cpp
        src/Base.h
        src/Animal.cpp
        src/Animal.h
        src/Damage.cpp
        src/Damage.h
        src/Health.cpp
        src/Health.h
        src/Range.cpp
        src/Range.h
        src/CloseCombat.cpp
        src/CloseCombat.h sprites/startscreen.h sprites/yoda_sprite.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
