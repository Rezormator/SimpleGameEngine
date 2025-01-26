#pragma once

#include <map>
#include "../GameObject/Camera/Camera.h"
// #include "../GameObject/Light/DirectionalLight/DirectionalLight.h"
// #include "../GameObject/Light/PointLight/PointLight.h"
// #include "../GameObject/Light/SpotLight/SpotLight.h"
#include "../GameObject/Model/Model.h"

class Scene {
private:
    Model *model;
    Camera *camera;
    // std::map<std::string, Model*> objects;
    // std::map<std::string, DirectionalLight*> directionLights;
    // std::map<std::string, PointLight*> pointLights;
    // std::map<std::string, SpotLight*> spotLights;
    GLvoid createObjects();
    GLvoid createLights();
    GLvoid drawLights() const;
public:
    Scene();
    ~Scene();
    GLvoid draw();
};
