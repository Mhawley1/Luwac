#version 330 core
layout (location = 2) in vec3 aPos;

layout (location = 3) in vec2 aTexCoord;

layout (location = 4) in vec3 aPos_1;

layout (location = 5) in vec2 aTexCoord_1;

//out vec3 ourColor;
out vec2 TexCoord;
uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(aPos, 1.0);
	//ourColor = aColor;
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}
