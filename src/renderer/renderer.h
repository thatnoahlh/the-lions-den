#ifndef RENDERER_H
#define RENDERER_H

// Initializes OpenGL and the rendering context
void initializeOpenGL();

// Prepares the frame for rendering
void beginFrame();

// Finalizes the frame and swaps buffers
void endFrame();

// Checks if the rendering window should close
bool shouldCloseWindow();

// Renders a model with the given texture
void renderModelWithTexture(unsigned int modelID, unsigned int textureID);

// Renders the GUI
void showGUI();

// Cleans up the rendering resources
void cleanupRenderer();

#endif // RENDERER_H