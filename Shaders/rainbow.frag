#version 330 core
out vec4 FragColor;

uniform float time;
in vec3 vertPos;

void main()
{
    FragColor = vec4(vertPos+0.5, 1.0f);
} 