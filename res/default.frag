#version 410 core
out vec4 FragColor;
// in vec2 TexCoord;
in vec4 color;

// uniform sampler2D ourTexture;

void main() {
    FragColor = color;
    // FragColor = texture(ourTexture, TexCoord) * Color; 
} 