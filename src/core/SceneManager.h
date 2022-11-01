#pragma once

#include <memory>
#include <unordered_map>
#include "Scene.h"

// class SceneManager {
// public:

//     void setActiveScene(Scene scene);
//     // Scene getActiveScene() { return m_activeScene; }

//     void update();

// private:

//     // Scene m_activeScene = NULL;

// 	std::vector<Scene> m_scenes = {};

// };

class SceneManager
{
public:
    SceneManager();

    // ProcessInput, Update, LateUpdate, and Draw will call the correspond methods of the active scene.
    void ProcessInput();
    void Update(float deltaTime);
    void LateUpdate(float deltaTime);
    // void Draw(Window &window);
    void Draw();

    // Adds a scene to the state machine and returns the id of that scene.
    unsigned int Add(std::shared_ptr<Scene> scene);

    // Transitions to scene with specified id.
    void SwitchTo(unsigned int id);

    // Removes scene from state machine.
    void Remove(unsigned int id);

private:
    // Stores all of the scenes associated with this state machine.
    std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;

    // Stores a reference to the current scene. Used when drawing/updating.
    std::shared_ptr<Scene> curScene;

    // Stores our current scene id. This is incremented whenever a scene is added.
    unsigned int insertedSceneID;
};
