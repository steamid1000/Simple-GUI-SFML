#include <unordered_map>
#include <memory>
#include "Scene.hpp"

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();
    void addScene(std::string, Scene *);
    void removeScene(std::string);
    void update();
    void switchScene(std::string);

private:
    std::unordered_map<std::string, std::shared_ptr<Scene>> scenesStorage;
    std::shared_ptr<Scene> currentScene;
};

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::addScene(std::string sceneName, Scene *tobeAddedScene)
{
    scenesStorage.insert(std::make_pair(sceneName, tobeAddedScene));
}

void SceneManager::removeScene(std::string sceneName)
{
    if (scenesStorage.find(sceneName) != scenesStorage.end())
    {
        scenesStorage.erase(sceneName);
        return;
    }
    throw std::runtime_error("The Scene was not found and hence not deleted");
}

void SceneManager::switchScene(std::string sceneName)
{
    if(scenesStorage.find(sceneName) == scenesStorage.end()) throw std::runtime_error("The scene you are looking for does not exist, exiting now\n");
    currentScene = scenesStorage.find(sceneName)->second;
}

void SceneManager::update()
{
    currentScene->render();
}

inline SceneManager SM;