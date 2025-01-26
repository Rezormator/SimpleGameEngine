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
    std::map<std::string, Light*> lights;
    GLvoid createObjects();
    GLvoid createLights();
    GLvoid setLights(Shader *shader) const;
public:
    Scene();
    ~Scene();
    GLvoid draw();
};
