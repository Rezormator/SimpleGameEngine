#pragma once

#include <map>
#include "../GameObject/Camera/Camera.h"
#include "../Light/DirectionalLight/DirectionalLight.h"
#include "../Light/PointLight/PointLight.h"
#include "../Light/SpotLight/SpotLight.h"
#include "../GameObject/Model/Model.h"

class Scene {
private:
    Camera *camera;
    std::map<std::string, Model*> models;
    std::map<std::string, DirectionalLight*> directionalLights;
    std::map<std::string, PointLight*> pointLights;
    std::map<std::string, SpotLight*> spotLights;
    GLvoid createObjects();
    GLvoid createLights();
    GLvoid setLights(Shader *shader) const;
public:
    Scene();
    ~Scene();
    GLvoid render();
};
