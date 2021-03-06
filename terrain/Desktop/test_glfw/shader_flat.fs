#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;


// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture4;

void main()
{
	// linearly interpolate between both textures (80% container, 20% awesomeface)
	vec4 texColor = texture(texture1, TexCoord);
	if(texColor.a < 0.1)
        discard;
	FragColor = texColor;
}
