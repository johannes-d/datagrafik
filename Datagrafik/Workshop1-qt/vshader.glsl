#version 330

in vec4 vPosition;
in vec4 vColor;
out vec4 color;
uniform mat4 M;
uniform mat4 P;

void
main()
{
  gl_Position =  P*M*vec4(vPosition);
  color = vColor;
}
