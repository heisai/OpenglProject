#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 normal;
uniform mat4 model;
uniform mat4 view;
uniform mat4 project;


out vec3 Vertpos;			
out vec3 NoralVector;		//∑®œÚ¡ø
void main()
{
	

	Vertpos = vec3(model * vec4(aPos, 1.0f));
	
	NoralVector = mat3(transpose(inverse(model))) * normal;  
	gl_Position = project * view *  vec4(Vertpos,1.0);
}