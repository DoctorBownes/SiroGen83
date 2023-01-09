#include "core.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SiroGen83/scene.h>
#include <SiroGen83/camera.h>
#include <SiroGen83/renderer.h>
#include <stdio.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //glViewport(0,0,width, height);
    glViewport(width * 0.25f, height * 0, width * 0.5f, height);
}

Core::Core() {
    _window = nullptr;
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    _window = glfwCreateWindow(1920, 1080, "SiroGen83", NULL, NULL);

    if (_window == NULL) {
        fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        glfwTerminate();
        return;
    }
    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
    glfwMakeContextCurrent(_window);

    if (!gladLoadGL()) {
        fprintf(stderr, "Failed to initialize GLAD.\n");
        glfwTerminate();
    }

    _instance = _instance->GetInstance();
}

void Core::Run(Scene* scene) {

    scene->GetInput()->Init(_window);

    scene->GetCamera()->X |= scene->renderpos << 8;

    _instance->SetUpMaintable(scene->Nametables, scene->renderpos);

    do {

        glClearColor(0.1f, 0.15f, 0.8f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        scene->update();

        for (Entity* it : scene->entities) {
            it->update();
        }

        scene->GetCamera()->update(scene->rendermode);
        _instance->RenderScene(scene);

        scene->GetCamera()->update();
        _instance->RenderScene(scene);

        glfwSwapBuffers(_window);
        glfwPollEvents();
    } while (!glfwWindowShouldClose(_window));
}
