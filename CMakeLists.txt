cmake_minimum_required(VERSION 3.25)
project(matches-sdl C)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME})
#target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic-errors -Wconversion -Wsign-conversion)
add_subdirectory(src)

# --- SDL2 SETUP --- (CLion/Windows)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2/x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "SDL2/x86_64-w64-mingw32")
set(SDL2_TTF_PATH "SDL2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})

install(FILES share/images/allumette.jpg	    DESTINATION ${CMAKE_INSTALL_DATADIR}/images/)
install(FILES "share/images/allumette 1.jpg"	DESTINATION ${CMAKE_INSTALL_DATADIR}/images/)
install(FILES "share/images/allumette 2.jpg"	DESTINATION ${CMAKE_INSTALL_DATADIR}/images/)
install(FILES share/images/feu.jpg	            DESTINATION ${CMAKE_INSTALL_DATADIR}/images/)
install(FILES share/images/icone.bmp	        DESTINATION ${CMAKE_INSTALL_DATADIR}/images/)

install(FILES share/polices/angelina.ttf	    DESTINATION ${CMAKE_INSTALL_DATADIR}/polices/)
install(FILES share/polices/arial.ttf       	DESTINATION ${CMAKE_INSTALL_DATADIR}/polices/)
install(FILES share/polices/firestarter.ttf 	DESTINATION ${CMAKE_INSTALL_DATADIR}/polices/)
install(FILES share/polices/freescpt.ttf        DESTINATION ${CMAKE_INSTALL_DATADIR}/polices/)
install(FILES share/polices/frscript.ttf	    DESTINATION ${CMAKE_INSTALL_DATADIR}/polices/)
install(FILES share/polices/times.ttf	        DESTINATION ${CMAKE_INSTALL_DATADIR}/polices/)