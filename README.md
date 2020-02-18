[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)[![forthebadge](https://forthebadge.com/images/badges/gluten-free.svg)](https://forthebadge.com)[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)

# TheBase
The base code for any project.

Features:

* Functional Programming (The entire codebase is functional)
* Fast Development (TheBase will speed up development time)
* Ease-of-Use (Functions are worded with easy to understand names)
* Differentiated Modules (Only need a renderer? Take the rendering module. Already have a rending engine? Take our game engine.)

## Building
 When cloning from github make sure you clone recursively since glfw is built with the rendering module.
 ~~~ 
 git clone https://github.com/STEAKISAWAKE/TheBase --recursive 
 ~~~
 Then use CMake to generate project files for which system you are on.
 Then build the code using the generated files.
 

## Different Modules

 ### Math Module
  * Used in both the Game Module and the Render Module so you will be using it eaither way. It can be overriden with your math that you already have.
  * The Base could also be used as a math library since building the Game Module and the Render Module can be disabled.
 ### Game Module
  * Used to make your game, has many functions and objects that will make it eaiser to code.
  * This includes Worlds Objects(Levels), Game Objects(Host of levels), Actor Objects(Things inside your game).
  * Very similar to Unreal Engine 4's type of engine style. I based it off of that idea.
 ### Render Module
  * Used to draw to a window, it creates a window with the proper api (OpenGL, Vulkan). Many rendering functions/objects such as meshes which can be loaded from file.
 ### Audio Module
  * Plays audio and music/sound effects.

 ### Soon To Come Modules
  * Physics Module, Allows for gravity and collision simulation along with raycasting.
  * Neworking Module, It will allow for communications between clients and servers using TCP and UDP
  * Editor Module, It is a editor to make worlds and other parts of your game

  Using CMake you can eaither use the Game Module, Rendering Module or both.
  
## Git Branches (Not Used Yet)

 ### master - Stable (Only current branch)
  * The master branch is always the latest release code
  * Always the most stable
  * Focus on quality
  
 ### ptb (public test branch) - Beta
  * The public test branch is for testing new features.
  * New features work and might need to have small bug fixes before merging to master.
  
 ### dev - Alpha
  * The dev branch is for adding new features and testing them.
  * This is the least stable branch and is more likely to cause errors, bugs and crashes
  * <b>*USE AT YOUR OWN RISK*</b>
 
  
