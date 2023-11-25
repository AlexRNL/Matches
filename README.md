Matches
=======

Célèbre jeu des allumettes réalisé en C (utilisation de la SDL)

## Build

### Windows build (CLion with CMake)

* Download the latest [SDL Development Libraries (MinGW version)](https://www.libsdl.org/download-2.0.php)
* Download the [SDL2 Cmake Scripts](https://github.com/tcbrindle/sdl2-cmake-scripts)
* Create a cmake/modules directory in your project root and unzip all cmake scripts there.
* Unzip the SDL Development libraries in your project root, rename the folder to 'SDL2'
* Mark the SDL2 folder as excluded in Clion (Optional)
* Copy the SDL2.dll from the SDL2 folder into your cmake-build-debug folder:
    - For 64 bits version it's located at x86_64-w65-mingw32/bin/SDL2.dll
    - For 32 bits version it's located at i686-w64-mingw32/bin/SDL2.dll

#### Important READ

* The paths should be exactly as told otherwise change the folder's paths inside the CMakeLists.txt.
* MingGw should be the default toolchains for Clion.

#### Setup SDL2 Image

1. Download the [SDL Image Development Release](https://github.com/libsdl-org/SDL_image/releases)
2. Inside your SDL2 Image folder (downloaded from step 1), select the version you are using for SDL2 and copy it to your
   SDL2 folder in your project (It won't override anything)
3. Put the SDL2_image.dll from the SDL2 Image folder into your cmake-build-debug folder.
4. Add to the CMakeList:
    ``` 
   set(SDL2_IMAGE_PATH "SDL2/x86_64-w64-mingw32")
   find_package(SDL2_image REQUIRED) 
   ```