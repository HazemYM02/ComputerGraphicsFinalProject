
# Hazem Mahmoud Final Project: 3D Graphics with OpenGL

This project demonstrates the basics of 3D graphics using OpenGL and GLUT. The application renders a dynamic scene containing a color cube, a pyramid, and a rotating teapot, showcasing various transformations like translation, rotation, and scaling. Additionally, the program integrates simple lighting effects to enhance the visualization.

## Features

- **Dynamic 3D Transformations**: Users can interact with the scene using keyboard inputs to translate, rotate, and scale objects in real-time.
- **Lighting Effects**: The scene includes configurable lighting that can be adjusted using keyboard commands to change the light position and intensity, demonstrating ambient, diffuse, and specular lighting effects.
- **Interactive Controls**: Control the objects and lighting in the scene with specific keyboard keys to observe the effects of different OpenGL functions.

## Installation and Running the Program

### Prerequisites

- C++ Compiler (e.g., GCC, Clang)
- OpenGL library
- GLUT library

### Compiling the Program

To compile the program, use the following command (make sure you are in the project directory):

```bash
g++ -o finalProject main.cpp -lGL -lGLU -lglut
```

### Running the Program

Once compiled, you can run the program by executing:

```bash
./finalProject
```

## Controls

- **Translation**:
  - `W/A/S/D`: Move the objects up/left/down/right along the X and Y axes.
  - `Q/Z`: Move the objects in/out of the screen along the Z axis.
- **Rotation**:
  - `T/G`: Rotate left/right along the X axis.
  - `Y/H`: Rotate up/down along the Y axis.
  - `U/J`: Rotate clockwise/counterclockwise along the Z axis.
- **Scaling**:
  - `O/L`: Scale up/down the objects.
- **Light Position Adjustment**:
  - `X/C`: Move the light right/left along the X axis.
  - `V/B`: Move the light up/down along the Y axis.
  - `M/N`: Move the light in/out of the screen along the Z axis.

## Project Structure

- **main.cpp**: Contains the main logic for initializing OpenGL, setting up the scene, and handling user inputs.

## Author

- **Hazem Mahmoud**
