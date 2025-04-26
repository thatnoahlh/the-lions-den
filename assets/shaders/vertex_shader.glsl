#version 130

in vec3 aPos;
in vec2 aTexCoord;
in vec3 aNormal; // Add normals for lighting

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 TexCoord;
out vec3 FragPos;  // Pass the fragment position to the fragment shader
out vec3 Normal;   // Pass the normal to the fragment shader

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    TexCoord = aTexCoord;
    FragPos = vec3(model * vec4(aPos, 1.0)); // Transform vertex position to world space
    Normal = mat3(model) * aNormal; // Transform normal to world space
}