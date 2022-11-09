#include "core.h"
#include <SiroGen83/scene.h>
#include <SiroGen83/camera.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdio.h>

const char* vertex_shader = "#version 330 core\n"
"layout(location = 0) in vec4 vertexPosition;\n"
"uniform mat4 MVP;\n"
"void main()\n"
"{\n"
"	gl_Position = MVP * vec4(vertexPosition.x,vertexPosition.y,0.0f, 1.0f);\n"
"};\0";

const char* fragment_shader = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"};\0";

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
    //Shader stuff
    GLuint VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VertexShader, 1, &vertex_shader, nullptr);
    glCompileShader(VertexShader);

    GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FragmentShader, 1, &fragment_shader, nullptr);
    glCompileShader(FragmentShader);

    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, VertexShader);
    glAttachShader(shaderProgram, FragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);

    glUseProgram(shaderProgram);

    GLuint Init;
    glGenVertexArrays(1, &Init);
    glBindVertexArray(Init);

    VertexBuffer[0] =  -0.5f * 256.0f;
    VertexBuffer[1] =   0.5f * 240.0f;
    VertexBuffer[2] = 0.0f;
    VertexBuffer[3] = 0.0f;

    VertexBuffer[4] = 0.5f * 256.0f;
    VertexBuffer[5] = 0.5f * 240.0f;
    VertexBuffer[6] = 1.0f;
    VertexBuffer[7] = 0.0f;
                       
    VertexBuffer[8] =   0.5f * 256.0f;
    VertexBuffer[9] = -0.5f * 240.0f;
    VertexBuffer[10] = 1.0f;
    VertexBuffer[11] = 1.0f;
                       
    VertexBuffer[12] =   0.5f * 256.0f;
    VertexBuffer[13] = -0.5f * 240.0f;
    VertexBuffer[14] = 1.0f;
    VertexBuffer[15] = 1.0f;

    VertexBuffer[16] = -0.5f * 256.0f;
    VertexBuffer[17] = -0.5f * 240.0f;
    VertexBuffer[18] = 0.0f;
    VertexBuffer[19] = 1.0f;

    VertexBuffer[20] = -0.5f * 256.0f;
    VertexBuffer[21] = 0.5f * 240.0f;
    VertexBuffer[22] = 0.0f;
    VertexBuffer[23] = 0.0f;

    glDisable(GL_DEPTH_TEST);

    glGenBuffers(1, &VertexVBO);
    glBindBuffer(GL_ARRAY_BUFFER, VertexVBO);
    glBufferData(GL_ARRAY_BUFFER, (sizeof(VertexBuffer) / sizeof(VertexBuffer[0])) * 4, VertexBuffer, GL_STATIC_DRAW);
}

void Core::Run(Scene* scene) {
    CurrentScene = scene;
    do {

        glClearColor(0.1f, 0.15f, 0.8f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        scene->GetCamera()->update();

        glm::mat4 MVP = scene->GetCamera()->GetProMat() * scene->GetCamera()->GetCamMat();

        GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        for (int i = 0; i < (sizeof(scene->entities) / sizeof(scene->entities[0])); i++) {
         //   scene
        }

        GLuint vertexPositionID = glGetAttribLocation(shaderProgram, "vertexPosition");
        glEnableVertexAttribArray(vertexPositionID);
        glBindBuffer(GL_ARRAY_BUFFER, VertexVBO);
        glVertexAttribPointer(
            vertexPositionID,   // attribute 0. No particular reason for 0, but must match the layout in the shader.
            4,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );
        glDrawArrays(GL_TRIANGLES, 0, 6); // Starting from vertex 0; 3 vertices total -> 1 triangle
        glDisableVertexAttribArray(vertexPositionID);

        glfwSwapBuffers(_window);
        glfwPollEvents();
    } while (!glfwWindowShouldClose(_window));
}
