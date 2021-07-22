//fragment shader source code
#version 330 core
out vec4 FragColor;

//gets the color sent out by default.vert
in vec3 color;

void main()
{
    FragColor = vec4(color, 1.0f);
}