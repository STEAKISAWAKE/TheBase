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
 ### Game Module
  * Used to make your game, has many functions and objects that will make it eaiser to code.
 ### Render Module
  * Used to draw to a window, it creates a window with the proper api (OpenGL, Vulkan). Many rendering functions/objects such as meshes which can be loaded from file.

  Using CMake you can eaither use the Game Engine, Rendering Engine or both.
  
