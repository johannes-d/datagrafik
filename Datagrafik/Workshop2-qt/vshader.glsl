#version 330

in vec3 vPosition;
in vec4 vColor;
out vec4 color;
uniform mat4 M;

void
main()
{
    gl_Position =  M*vec4(vPosition, 1.0);
    color = vColor;
}
