#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <string>
#include <vector>

// Function to load a model and return vertex and index data
bool loadModel(const std::string& filePath, std::vector<float>& vertexData, std::vector<unsigned int>& indices);

#endif // MODELLOADER_H