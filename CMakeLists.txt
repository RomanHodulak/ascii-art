cmake_minimum_required(VERSION 3.10)
project(ascii_art)

set(CMAKE_CXX_STANDARD 11)

link_libraries(ncurses)
add_executable(ascii_art
    src/main.cpp
    src/Frame.h
    src/ImageSource.h
    src/ImageSource.cpp
    src/StaticImageSource.h
    src/StaticImageSource.cpp
    src/MultiImageSource.h
    src/MultiImageSource.tpp
    src/BmpImageSource.h
    src/BmpImageSource.tpp
    src/BmpImageSource.cpp
    src/Filter.h
    src/Pixel.h
    src/Pixel.tpp
    src/Player.h
    src/MultiFilter.h
    src/MultiFilter.tpp
    src/AsciiPrinter.h
    src/InvertFilter.h
    src/BrightnessFilter.h
    src/Editor.h
    src/Editor.tpp
    src/Editor.cpp
        src/AsciiPrinter.cpp src/Pixel.cpp src/MultiImageSource.cpp src/GreyscaleFilter.cpp src/GreyscaleFilter.h src/BrightnessFilter.cpp src/InvertFilter.cpp src/MultiFilter.cpp src/Frame.cpp src/Frame.tpp src/Player.cpp src/NCursesBuf.cpp src/NCursesBuf.h src/ui/Rectangle.cpp src/ui/Rectangle.h src/ui/Control.cpp src/ui/Control.h src/ui/PlayerControl.cpp src/ui/PlayerControl.h src/ui/FilterPanelControl.cpp src/ui/FilterPanelControl.h src/ui/FilterMenuControl.cpp src/ui/FilterMenuControl.h src/ui/FilterPanelControl.tpp src/InvalidFileException.cpp src/InvalidFileException.h)
