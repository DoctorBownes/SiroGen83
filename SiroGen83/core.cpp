#include "core.h"
#include <SiroGen83/scene.h>
#include <SiroGen83/camera.h>
#include <SiroGen83/renderer.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stdio.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
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
    do {

        glClearColor(0.1f, 0.15f, 0.8f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        scene->GetCamera()->update();

        scene->update();

        for (int i = 0; i < (sizeof(scene->entities) / sizeof(scene->entities[0])); i++) {
            scene->entities[0]->update();
        }

        _instance->RenderScene(scene);

        glfwSwapBuffers(_window);
        glfwPollEvents();
    } while (!glfwWindowShouldClose(_window));
}
