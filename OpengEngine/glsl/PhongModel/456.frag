#version 330 core
out vec4 FragColor;
struct Light
{
	vec3 positon;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct Material 
{
	
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shiniess;
};

in vec3 Vertpos;			
in vec3 NoralVector;		//∑®œÚ¡ø



uniform Material MaterialData;
uniform Light LightData;

void main()
{
	vec3 ambient = LightData.ambient * MaterialData.ambient;
	vec3 LightVector = (LightData.positon - Vertpos);
	vec3 N = normalize(NoralVector);
	vec3 L = normalize(LightVector);
	float cosTheta  = dot(L,N);
	vec3 diffuse = LightData.diffuse * (MaterialData.diffuse * max(cosTheta,0.0));
	
	vec3 V = normalize(vec3(0.0f, 0.0f, 3.0f) - Vertpos);

	vec3 R = normalize(reflect(-L,N));

	

	float cosPhi = dot(V,R);


	

	

	vec3 specular = LightData.specular * (MaterialData.specular * pow(max(cosPhi,0.0),MaterialData.shiniess));
	
	vec3 result = ambient + diffuse + specular;

	FragColor = vec4(result,1.0f);
}