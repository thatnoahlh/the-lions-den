#include "modelLoader.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>
#include <iostream>

// Function to load a .obj model and extract vertex and index data
bool loadModel(const std::string& filePath, std::vector<float>& vertexData, std::vector<unsigned int>& indices) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(filePath, aiProcess_Triangulate | aiProcess_JoinIdenticalVertices);

    if (!scene || !scene->HasMeshes()) {
        std::cerr << "Error: Failed to load model from " << filePath << std::endl;
        return false;
    }

    const aiMesh* mesh = scene->mMeshes[0]; // Assume the model has one mesh

    // Extract vertex data (position and texture coordinates)
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        vertexData.push_back(mesh->mVertices[i].x);
        vertexData.push_back(mesh->mVertices[i].y);
        vertexData.push_back(mesh->mVertices[i].z);

        if (mesh->mTextureCoords[0]) {
            vertexData.push_back(mesh->mTextureCoords[0][i].x);
            vertexData.push_back(mesh->mTextureCoords[0][i].y);
        } else {
            vertexData.push_back(0.0f);
            vertexData.push_back(0.0f);
        }
    }

    // Extract index data
    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        const aiFace& face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }

    return true;
}