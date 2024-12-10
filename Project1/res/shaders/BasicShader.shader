#shader vertex
#version 330 core

layout(location = 0) out vec2 TexCoord;

void main()
{
	TexCoord.x = (gl_VertexID == 2)? 2.0 : 0.0;
	TexCoord.y = (gl_VertexID == 1)? 2.0 : 0.0;

	gl_Position = vec4(2.0 * TexCoord - 1.0, 0.0, 1.0);
};

#shader fragment
#version 330 core

layout(location = 0) in vec2 TexCoord;

out vec3 outColor;

uniform sampler2D u_buffer;

void main() 
{
	outColor = texture(u_buffer, TexCoord).rgb;
};