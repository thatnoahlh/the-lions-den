#ifndef RENDERER_H
#define RENDERER_H

#include <string>

// Function to initialize OpenGL and the rendering environment
void initializeOpenGL();

// Function to load a 3D model
void loadModel(const std::string& path);

// Function to load a texture
unsigned int loadTexture(const std::string& path);

// Function to render the 3D scene
void renderScene();

#endif
