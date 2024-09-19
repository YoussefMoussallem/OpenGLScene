#version 330 core

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

struct Ligth {
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Material material;
uniform Ligth ligth;
uniform vec3 viewPos;
in vec3 fcolor;
in vec3 Normal;
in vec3 FragPos;
out vec4 fragColor;

void main() {
	vec3 ambient = ligth.ambient*material.ambient ;

	vec3 norm = normalize(Normal);
	vec3 ligthdirection = normalize(ligth.position - FragPos);
	float diff = max(dot(norm,ligthdirection), 0.0);
	vec3 diffuse = ligth.diffuse * (diff * material.diffuse);

	vec3 viewdirection = normalize(viewPos - FragPos);
	vec3 reflectdir = reflect(-ligthdirection, norm);
	float spec = pow(max(dot(viewdirection, reflectdir), 0.0), material.shininess * 128);
	vec3 specular = ligth.specular * (material.specular * spec);

	float distance = length(ligth.position - FragPos);
	float attenuation = 1.0 / (1+0.01*distance+0.000001*(distance*distance));
	ambient = ambient * attenuation;
	diffuse = diffuse * attenuation;
	specular = specular * attenuation;
	fragColor = vec4(vec3(ambient+diffuse+specular) , 1  );
}