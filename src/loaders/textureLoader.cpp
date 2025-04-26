#include "textureLoader.h"
#include <iostream>
#include <GL/glew.h>

unsigned int loadTexture(const std::string& path) {
    unsigned int textureID;
    glGenTextures(1, &textureID);
    if (textureID == 0) {
        std::cerr << "Error: Failed to generate texture for " << path << std::endl;
        return 0;
    }

    // Add your texture loading logic here
    std::cout << "Loaded texture ID: " << textureID << " from " << path << std::endl;
    return textureID;
}