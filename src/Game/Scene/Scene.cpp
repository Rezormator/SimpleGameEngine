#include "Scene.h"
#include <ranges>
#include "../../Managers/Managers.h"
#include "../GameObject/Model/Model.h"

Scene::Scene() {
    camera = new Camera();
    createObjects();
    createLights();
}

Scene::~Scene() {
    delete camera;
    for (const auto &model: models | std::views::values) {
        delete model;
    }
    for (const auto &directionalLight: directionalLights | std::views::values) {
        delete directionalLight;
    }
    for (const auto &pointLight: pointLights | std::views::values) {
        delete pointLight;
    }
    for (const auto &spotLight: spotLights | std::views::values) {
        delete spotLight;
    }
}

GLvoid Scene::render() {
    camera->update();
    camera->set(Managers::getShaderManager()->getColorShader());
    camera->set(Managers::getShaderManager()->getTextureShader());

    setLights(Managers::getShaderManager()->getColorShader());
    setLights(Managers::getShaderManager()->getTextureShader());

    models["backpack"]->render();

    spotLights["2"]->setPosition(camera->getPosition());
    spotLights["2"]->setDirection(camera->getFront());
}

GLvoid Scene::createObjects() {
    models["backpack"] = new Model("../resources/models/backpack/backpack.obj");
}

GLvoid Scene::createLights() {
    pointLights["1"] = new PointLight();
    pointLights["1"]->setPosition({1.0f, 3.0f, 5.0f});
    // directionLights["1"] = new DirectionalLight();
    // spotLights["1"] = new SpotLight();
    // spotLights["1"]->setDirection({0.0f, 0.0f, 1.0f});
    spotLights["2"] = new SpotLight();
    spotLights["2"]->setRadius(1000);
    // spotLights["2"]->setOuterCutOff(25.0);
    // spotLights["2"]->setInnerCutOff(22.0);
}

GLvoid Scene::setLights(Shader *shader) const {
    for (const auto &directionalLight: directionalLights | std::views::values) {
        directionalLight->set(shader);
    }
    for (const auto &pointLight: pointLights | std::views::values) {
        pointLight->set(shader);
    }
    for (const auto &spotLight: spotLights | std::views::values) {
        spotLight->set(shader);
    }
}

