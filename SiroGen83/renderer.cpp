#include "renderer.h"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <stdio.h>

const char* vertex_shader = "#version 330 core\n"
"layout(location = 0) in vec4 vertexPosition;\n"
"uniform mat4 MVP;\n"
"out vec2 UV;\n"
"void main()\n"
"{\n"
"	gl_Position = MVP * vec4(vertexPosition.x,vertexPosition.y,0.0f, 1.0f);\n"
"	UV = vec2(vertexPosition.z,vertexPosition.w);\n"
"};\0";

const char* fragment_shader = "#version 330 core\n"
"in vec2 UV;\n"
"out vec4 FragColor;\n"
"uniform sampler2D myTextureSampler;\n"
"void main()\n"
"{\n"
"	FragColor = texture2D(myTextureSampler, UV);\n"
"};\0";

Renderer* Renderer::_instance = 0;

Renderer::Renderer() {
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

    //Set-up maintables
    VertexBuffer[0] = -0.5f * 512;
    VertexBuffer[1] = 0.5f * 480;
    VertexBuffer[2] = 0.0f;
    VertexBuffer[3] = 0.0f;

    VertexBuffer[4] = 0.5f * 512;
    VertexBuffer[5] = 0.5f * 480;
    VertexBuffer[6] = 1.0f;
    VertexBuffer[7] = 0.0f;

    VertexBuffer[8] = 0.5f * 512;
    VertexBuffer[9] = -0.5f * 480;
    VertexBuffer[10] = 1.0f;
    VertexBuffer[11] = 1.0f;

    VertexBuffer[12] = 0.5f * 512;
    VertexBuffer[13] = -0.5f * 480;
    VertexBuffer[14] = 1.0f;
    VertexBuffer[15] = 1.0f;

    VertexBuffer[16] = -0.5f * 512;
    VertexBuffer[17] = -0.5f * 480;
    VertexBuffer[18] = 0.0f;
    VertexBuffer[19] = 1.0f;

    VertexBuffer[20] = -0.5f * 512;
    VertexBuffer[21] = 0.5f * 480;
    VertexBuffer[22] = 0.0f;
    VertexBuffer[23] = 0.0f;

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, (sizeof(VertexBuffer) / sizeof(VertexBuffer[0])) * 4, VertexBuffer, GL_STATIC_DRAW);
}

void Renderer::RenderScene(Scene* scene) {

    SetMaintables(scene); //TODO implement int renderpos

    for (Entity* it : scene->entities) {
        glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1), glm::vec3(it->position.x, it->position.y, 0.0f));
        
        glm::mat4 MVP = scene->GetCamera()->GetProMat() * scene->GetCamera()->GetCamMat() * TranslationMatrix;

        GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        if (it->vertex_buffer) {
            RenderEntity(it);
        }
    }
}

void Renderer::SetMaintables(Scene* scene) {
    glm::mat4 MVP = scene->GetCamera()->GetProMat() * scene->GetCamera()->GetCamMat();

    GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    if (once) {
        int overwrite_pos = 0; //change overwrite_pos // + (y * width)
        for (int y = 0; y < 16; y++) {
            overwrite_pos = 0 + y; //change overwrite_pos // + (y * width)
            for (int x = 0 + y; x < 240; x += 16) {
                Maintables[0].tiles[overwrite_pos] = scene->Nametables[0]->tiles[x];
                overwrite_pos += 32;
            }
        }
        once = false;
    }

    char* tempcanvas = (char*)malloc(16 * 15 * 16 * 16 + 1);
    int var = 0;
    int var2 = 0;
    int var3 = 0;
    for (int y = 1; y <= 15; y++)
    {
        for (int j = 1; j <= 16; j++)
        {
            for (int x = 0 + var2; x < 16 * y; x++)
            {
                for (int i = 0 + var; i < 16 * j; i++)
                {
                    if (scene->Nametables[0]->tiles[0]->pixels[0] == 1) {
                        pixelcanvas.push_back(255);
                        pixelcanvas.push_back(255);
                        pixelcanvas.push_back(255);
                        pixelcanvas.push_back(255);
                    }
                    else {
                        pixelcanvas.push_back(0);
                        pixelcanvas.push_back(0);
                        pixelcanvas.push_back(0);
                        pixelcanvas.push_back(255);
                    }
                    var3++;
                }
            }
            var += 16;
        }
        var = 0;
        var2 += 16;
    }
    //Firetruck this code ;)
    free(tempcanvas);

    //WIP
    for (int i = 0; i < 184320; i++) {
            pixelcanvas.push_back(0);
            pixelcanvas.push_back(0);
            pixelcanvas.push_back(0);
            pixelcanvas.push_back(255);
    }

    glGenTextures(1, &texture_buffer);
    glBindTexture(GL_TEXTURE_2D, texture_buffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 512, 480, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelcanvas.data());
    glGenerateMipmap(GL_TEXTURE_2D);

    pixelcanvas.clear();

    GLuint vertexPositionID = glGetAttribLocation(shaderProgram, "vertexPosition");
    glEnableVertexAttribArray(vertexPositionID);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
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
}

void Renderer::GenerateSprite(Entity* entity, char* canvas, char width, char height) {

    VertexBuffer[0] =  -0.5f * width;
    VertexBuffer[1] =   0.5f * height;
    VertexBuffer[2] = 0.0f;
    VertexBuffer[3] = 0.0f;

    VertexBuffer[4] = 0.5f * width;
    VertexBuffer[5] = 0.5f * height;
    VertexBuffer[6] = 1.0f;
    VertexBuffer[7] = 0.0f;

    VertexBuffer[8] =   0.5f * width;
    VertexBuffer[9] = -0.5f * height;
    VertexBuffer[10] = 1.0f;
    VertexBuffer[11] = 1.0f;

    VertexBuffer[12] =   0.5f * width;
    VertexBuffer[13] = -0.5f * height;
    VertexBuffer[14] = 1.0f;
    VertexBuffer[15] = 1.0f;

    VertexBuffer[16] = -0.5f * width;
    VertexBuffer[17] = -0.5f * height;
    VertexBuffer[18] = 0.0f;
    VertexBuffer[19] = 1.0f;

    VertexBuffer[20] = -0.5f * width;
    VertexBuffer[21] = 0.5f * height;
    VertexBuffer[22] = 0.0f;
    VertexBuffer[23] = 0.0f;

    glGenBuffers(1, &entity->vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, entity->vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, (sizeof(VertexBuffer) / sizeof(VertexBuffer[0])) * 4, VertexBuffer, GL_STATIC_DRAW);

    for (int i = 0; i < width * height; i++) {
        if (canvas[i] == 1) {
            pixelcanvas.push_back(255);
            pixelcanvas.push_back(255);
            pixelcanvas.push_back(255);
            pixelcanvas.push_back(255);
        } else {
            pixelcanvas.push_back(0);
            pixelcanvas.push_back(0);
            pixelcanvas.push_back(0);
            pixelcanvas.push_back(255);
        }
    }

    glGenTextures(1, &entity->texture_buffer);
    glBindTexture(GL_TEXTURE_2D, entity->texture_buffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelcanvas.data());
    glGenerateMipmap(GL_TEXTURE_2D);

    pixelcanvas.clear();
}

void Renderer::RenderEntity(Entity* entity) {
    glBindTexture(GL_TEXTURE_2D, entity->texture_buffer);

    GLuint vertexPositionID = glGetAttribLocation(shaderProgram, "vertexPosition");
    glEnableVertexAttribArray(vertexPositionID);
    glBindBuffer(GL_ARRAY_BUFFER, entity->vertex_buffer);
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
}
