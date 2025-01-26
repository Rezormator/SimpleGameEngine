#version 330 core

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

#define DIRECTIONAL_LIGHTS_COUNT 1
#define POINT_LIGHTS_COUNT 1
#define SPOT_LIGHTS_COUNT 1

struct Material {
    vec3 diffuse;
    vec3 specular;
    vec3 emission;
    float shininess;
};

struct DirLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
    vec3 position;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight {
    vec3 position;
    vec3 direction;
    float innerCutOff;
    float outerCutOff;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform vec3 viewPos;
uniform Material material;
uniform DirLight directionalLights[DIRECTIONAL_LIGHTS_COUNT];
uniform PointLight pointLights[POINT_LIGHTS_COUNT];
uniform SpotLight spotLights[SPOT_LIGHTS_COUNT];

vec3 calculateDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 calculatePointLight(PointLight light, vec3 normal, vec3 viewDir, vec3 fragPos);
vec3 calculateSpotLight(SpotLight light, vec3 normal, vec3 viewDir, vec3 fragPos);

void main() {
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    vec3 result;
//    for (int i = 0; i < DIRECTIONAL_LIGHTS_COUNT; i++) {
//        result += calculateDirLight(directionalLights[i], norm, viewDir);
//    }
//
//    for (int i = 0; i < POINT_LIGHTS_COUNT; i++) {
//        result += calculatePointLight(pointLights[i], norm, viewDir, FragPos);
//    }

//    for (int i = 0; i < SPOT_LIGHTS_COUNT; i++) {
//        result += calculateSpotLight(spotLights[i], norm, viewDir, FragPos);
//    }

    result += material.emission;
    FragColor = vec4(result, 1.0);
}

vec3 calculateDirLight(DirLight light, vec3 normal, vec3 viewDir) {
    vec3 lightDir = normalize(-light.direction);

    vec3 ambient = light.ambient * material.diffuse;

    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * material.diffuse;

    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * material.specular;

    return (ambient + diffuse + specular);
}

vec3 calculatePointLight(PointLight light, vec3 normal, vec3 viewDir, vec3 fragPos) {
    vec3 lightDir = normalize(light.position - fragPos);
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    vec3 ambient = light.ambient * material.diffuse;

    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * material.diffuse;

    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * material.specular;

//    return (ambient + diffuse + specular);
    return (ambient + diffuse + specular) * attenuation;
}

vec3 calculateSpotLight(SpotLight light, vec3 normal, vec3 viewDir, vec3 fragPos) {
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    vec3 lightDir = normalize(light.position - fragPos);
    float theta = dot(lightDir, normalize(-light.direction));

    if (theta <= light.outerCutOff) {
        return light.ambient * material.diffuse * attenuation;
    }

    vec3 ambient = light.ambient * material.diffuse;

    float epsilon = light.innerCutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * material.diffuse;

    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * material.specular;

    return (ambient + diffuse * intensity + specular * intensity) * attenuation;
}