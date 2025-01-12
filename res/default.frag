#version 410 core
out vec4 FragColor;

in vec4 Color;
in vec2 TexCoord;

uniform sampler2D texture1;

void main() {
    // FragColor = Color;
    FragColor = texture(texture1, TexCoord); 
} 