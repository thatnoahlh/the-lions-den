#include "modelLoader.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>
#include <iostream>

// Function to load a .obj model and extract vertex and index data
bool loadModel(const std::string& filePath, std::vector<float>& vertexData, std::vector<unsigned int>& indices) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(filePath, aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_GenNormals);

    if (!scene || !scene->HasMeshes()) {
        std::cerr << "Error: Failed to load model from " << filePath << std::endl;
        return false;
    }

    // Loop through all meshes in the model
    for (unsigned int meshIndex = 0; meshIndex < scene->mNumMeshes; meshIndex++) {
        const aiMesh* mesh = scene->mMeshes[meshIndex];

        // Extract vertex data
        for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
            // Positions
            vertexData.push_back(mesh->mVertices[i].x);
            vertexData.push_back(mesh->mVertices[i].y);
            vertexData.push_back(mesh->mVertices[i].z);

            // Normals
            if (mesh->mNormals) {
                vertexData.push_back(mesh->mNormals[i].x);
                vertexData.push_back(mesh->mNormals[i].y);
                vertexData.push_back(mesh->mNormals[i].z);
            } else {
                vertexData.push_back(0.0f);
                vertexData.push_back(0.0f);
                vertexData.push_back(0.0f);
            }

            // Texture Coordinates
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
    }

    return true;
}