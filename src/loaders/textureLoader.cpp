#include "textureLoader.h"
#include <iostream>
#include <GL/glew.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../renderer/stb_image.h"

unsigned int loadTexture(const std::string& path) {
    unsigned int textureID;
    glGenTextures(1, &textureID);

    if (textureID == 0) {
        std::cerr << "Error: Failed to generate texture for " << path << std::endl;
        return 0;
    }

    // Load the texture image using stb_image
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // Flip the image vertically
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

    if (data) {
        GLenum format;
        if (nrChannels == 1)
            format = GL_RED;
        else if (nrChannels == 3)
            format = GL_RGB;
        else if (nrChannels == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        // Set texture wrapping and filtering options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        std::cout << "Loaded texture ID: " << textureID << " from " << path << std::endl;
    } else {
        std::cerr << "Error: Failed to load texture image from " << path << std::endl;
        glDeleteTextures(1, &textureID);
        textureID = 0;
    }

    // Free image memory
    stbi_image_free(data);

    return textureID;
}