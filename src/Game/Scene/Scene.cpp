#include "Scene.h"
#include "../../Managers/Managers.h"

Scene::Scene() {
    camera = new Camera();
    camera->setPosition({0, 0, 0});
    createObjects();
    createLights();
    // model = new Model("../models/room/room.obj");
    // model->setScale({0.005f, 0.005, 0.005});
}

Scene::~Scene() {
    delete camera;
    // for (const auto &object: objects | std::views::values) {
    //     delete object;
    // }
    // for (const auto &directionLight: directionLights | std::views::values) {
    //     delete directionLight;
    // }
    // for (const auto &pointLight: pointLights | std::views::values) {
    //     delete pointLight;
    // }
    // for (const auto &spotLight: spotLights | std::views::values) {
    //     delete spotLight;
    // }
}

GLvoid Scene::draw() {
    const auto shader = Managers::getShaderManager()->getTextureShader();

    camera->update();
    camera->set(shader);

    // spotLights["2"]->setPosition(camera->getPosition());
    // spotLights["2"]->setDirection(camera->getFront());

    drawLights();

    // model->render(shader);
}

GLvoid Scene::createObjects() {
    // objects["Cube"] = new Object(Manager::getShaderManager()->getShader("texture"),
    //     "../src/Game/Object/Objects/Cube",
    //     {3.0f, 3.0f, 3.0f});
    // objects["Cube"]->setMaterial(Manager::getResourceManager()->getTexture("container"),
    //     Manager::getResourceManager()->getTexture("container-specular"),
    //     32);
}

GLvoid Scene::createLights() {
    // pointLights["1"] = new PointLight();
    // pointLights["1"]->setPosition({1.0f, 3.0f, 5.0f});
    // directionLights["1"] = new DirectionalLight();
    // // spotLights["1"] = new SpotLight();
    // // spotLights["1"]->setDirection({0.0f, 0.0f, 1.0f});
    // spotLights["2"] = new SpotLight();
    // spotLights["2"]->setRadius(1000);
    // spotLights["2"]->setOuterCutOff(25.0);
    // spotLights["2"]->setInnerCutOff(22.0);
}

GLvoid Scene::drawLights() const {
    // const auto shader = Manager::getShaderManager()->getShader("texture");
    // for (const auto &directionLight: directionLights | std::views::values) {
    //     directionLight->set(shader);
    // }
    // for (const auto &pointLight: pointLights | std::views::values) {
    //     pointLight->set(shader);
    // }
    // for (const auto &spotLight: spotLights | std::views::values) {
    //     spotLight->set(shader);
    // }
}

