# Thema-opdracht Games
## Trello Board
https://trello.com/b/1WzBfOIa/thema-game

## Building
To build the game SFML is needed to be installed as an dependency.

### Windows
The environment variable ```SFML_ROOT``` needs to be set to the extracted SFML
library directory. In cmake-gui set the source directory to the root of the git
repository and the build directory to a subfolder called build. Next click
Configure at the bottom of the screen and select your version of visual studio
then after the configuring is done hit generate. Now the visual studio project
solution is created in the build directory ready to be opened. On the first time
it is openened the target ```thema-game``` needs to be set to the startup
project by right clicking it and selecting it. Lastly after building the project
the DLL's from SFML's bin directory need to be put into the build directory of
visual studio.

### Linux
Within the root of the git repository create a directory build and then cd into
it. Inside it run the command ```cmake ..``` and then ```make``` to build it
after it finished configuring.