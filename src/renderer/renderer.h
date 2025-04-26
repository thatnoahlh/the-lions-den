#ifndef RENDERER_H
#define RENDERER_H

#include <string>

// Function to initialize OpenGL and the rendering environment
void initializeOpenGL();

// Function to load a 3D model
void loadModel(const std::string& path);

// Function to load a texture
unsigned int loadTexture(const std::string& path);

// Function to render a model with a texture
void renderModelWithTexture(const std::string& modelPath, unsigned int textureID);

// Function to display the GUI
void showGUI();

#endif