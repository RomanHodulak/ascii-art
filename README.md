# ASCII art
Loads BMP images and displays them in ASCII art. Multiple images can be played as animation.

This project is a coursework for Programming and Algorithmics 2 at [FIT CTU](https://fit.cvut.cz/).

## Specification

The program:
* Loads 1 to n images of BMP format and renders them to command-line in grey scale ASCII art.
* Maps pixel color (whiteness) of 0 to 255 to ASCII character via map loaded from a file.
* Gets filenames of the map file and 1 to n bitmaps as command-line arguments.
* Features color inversion and brightness adjustment filters.
* Features animation player (in case of more than 1 image) and trivial animation editation tools in the form of switching or removing frames.
* Features animation playback in forward or backward direction.
* Implements custom BMP parser.
* Lets user play/pause the animation, change the speed and direction of the playback and frame-by-frame skipping.
* Uses NCurses library for rendering to command line.

## Usage

Assuming you have [make](https://www.gnu.org/software/make/) installed, run these commands to:

### Compile and run
```
cd {REPOSITORY_ROOT}
make compile
./hodulrom <map> <image> [more_images...]
```
You can use `{REPOSITORY_ROOT}/examples/map.txt` as a map file and `{REPOSITORY_ROOT}/examples/nyan{1,2,3,4,5,4,3,2}.bmp` as a sample animation.

### Generate documentation
```
cd {REPOSITORY_ROOT}
make doc
```
then navigate to `{REPOSITORY_ROOT}/hodulrom/doc/index.html` with your favourite web browser.

### Clean generated files
```
cd {REPOSITORY_ROOT}
make clean
```

## Controls

| Key               | Decription                                                                                                      |
|-------------------|-----------------------------------------------------------------------------------------------------------------|
| Escape            | Exit.                                                                                                           |
| Arrows left/right | Jump to previous/following frame.                                                                               |
| Arrows up/down    | Navigate in the UI.                                                                                             |
| Spacebar          | Play/pause animation playback.                                                                                  |
| Ctrl + Spacebar   | Play/pause animation playback in backward direction.                                                            |
| F                 | Increase framerate.                                                                                             |
| Ctrl + F          | Decrease framerate.                                                                                             |
| X                 | Mark/Unmark current frame as skipped (removed) from playback.                                                   |
| S                 | Switch frames. First press marks first frame, second press second frame that switches order with the first one. |
| A                 | Add image filter.                                                                                               |
| Enter             | Performs action in the menu (edit selected item, accept selection...).                                          |
| Delete            | Remove selected filter.                                                                                         |
