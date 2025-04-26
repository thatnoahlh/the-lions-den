#ifndef RENDERER_H
#define RENDERER_H

#include <glm/glm.hpp>
#include <vector>

// Initializes OpenGL and the rendering context
void initializeOpenGL();

// Prepares the frame for rendering
void beginFrame();

// Finalizes the frame and swaps buffers
void endFrame();

// Checks if the rendering window should close
bool shouldCloseWindow();

// Renders a model with the given texture
void renderModelWithTexture(unsigned int modelID, unsigned int textureID, const glm::mat4& view, const glm::mat4& projection, const glm::vec3& lightPos, const glm::vec3& lightColor, const glm::mat4& model);

// Renders the GUI
void showGUI();

// Cleans up the rendering resources
void cleanupRenderer();

// Sets the shader uniform for the view matrix
void setShaderUniform(const char* name, const glm::mat4& matrix);

// Sets the shader uniform for the projection matrix
void setShaderUniform(const char* name, const glm::vec3& vector);

// Activates the shader program
void useShaderProgram();

// Draws a model by its ID
void drawModel(unsigned int modelID);

// Initializes the shader program
void initializeShaderProgram(); // Add this declaration

// Initializes a model with vertex and index data
unsigned int initializeModel(const std::vector<float>& vertexData, const std::vector<unsigned int>& indices);

#endif // RENDERER_H