# TheBase
The base code for any project.

Features:

* Functional Programming (The entire codebase is functional)
* Fast Development (TheBase will speed up development time)
* Ease-of-Use (Functions are worded with easy to understand names)
* Differentiated Modules (Only need a renderer? Take the rendering module. Already have a rending engine? Take our game engine.)

## Differentiated Modules

 ### Math Module
  * Used in both the Game Module and the Render Module so you will be using it eaither way. It can be overriden with your math that you already have.
  * The Base could also be used as a math library since building the Game Module and the Render Module can be disabled.
 ### Game Module
  * Used to make your game, has many functions and objects that will make it eaiser to code.
  * This includes Worlds Objects(Levels), Game Objects(Host of levels), Actor Objects(Things inside your game).
  * Very similar to Unreal Engine 4's type of engine style. I based it off of that idea.
 ### Render Module
  * Used to draw to a window, it creates a window with the proper api (OpenGL, Vulkan). Many rendering functions/objects such as meshes which can be loaded from file.

 ### Soon To Come Modules
  * Audio Module, Plays audio and music/sound effects. The module will play MP3, WAV, and OGG files.
  * Neworking Module, Self explanitory. It will allow for communications between clients and servers using TCP and UDP

  Using CMake you can eaither use the Game Engine, Rendering Engine or both.
  
