#include "renderer.h"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <stdio.h>

const char* vertex_shader = "#version 330 core\n"
"layout(location = 0) in vec2 vertexPosition;\n"
"layout(location = 1) in vec2 uvPosition;\n"
"uniform mat4 MVP;\n"
"out vec2 UV;\n"
"void main()\n"
"{\n"
"	gl_Position = MVP * vec4(vertexPosition.x,vertexPosition.y,0.0f, 1.0f);\n"
"	UV = uvPosition;\n"
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

    UVBuffer[0] = 0.0f;
    UVBuffer[1] = 0.0f;
    UVBuffer[2] = 1.0f;
    UVBuffer[3] = 0.0f;
    UVBuffer[4] = 1.0f;
    UVBuffer[5] = 1.0f;
    UVBuffer[6] = 1.0f;
    UVBuffer[7] = 1.0f;
    UVBuffer[8] = 0.0f;
    UVBuffer[9] = 1.0f;
    UVBuffer[10] = 0.0f;
    UVBuffer[11] = 0.0f;

    for (int i = 0; i < 96 * 16; i++) {
        pixelcanvas.push_back(0);
        pixelcanvas.push_back(0);
        pixelcanvas.push_back(0);
        pixelcanvas.push_back(255);
    }

    glGenTextures(1, &tilemap_texture_buffer);
    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 96, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelcanvas.data());
    glGenerateMipmap(GL_TEXTURE_2D);

    pixelcanvas.clear();
}

void Renderer::SetUpMaintable(Nametable nametable) {

    //Set-up maintables
    int z = 0;
    for (int y = 0; y < 15; y++) {
        for (int x = 0; x < 16; x++) {
            MT_VertexBuffer.push_back((-0.5f + x) * 16.0f);
            MT_VertexBuffer.push_back((0.5f - y) * 16.0f);
            MT_VertexBuffer.push_back((0.5f + x) * 16.0f);
            MT_VertexBuffer.push_back((0.5f - y) * 16.0f);
            MT_VertexBuffer.push_back((0.5f + x) * 16.0f);
            MT_VertexBuffer.push_back((-0.5f - y) * 16.0f);
            MT_VertexBuffer.push_back((0.5f + x) * 16.0f);
            MT_VertexBuffer.push_back((-0.5f - y) * 16.0f);
            MT_VertexBuffer.push_back((-0.5f + x) * 16.0f);
            MT_VertexBuffer.push_back((-0.5f - y) * 16.0f);
            MT_VertexBuffer.push_back((-0.5f + x) * 16.0f);
            MT_VertexBuffer.push_back((0.5f - y) * 16.0f);

            MT_UVBuffer.push_back(0.0f + nametable.tiles[z] * (1.0f / 6.0f));
            MT_UVBuffer.push_back(0.0f);
            MT_UVBuffer.push_back((1.0f / 6.0f) + nametable.tiles[z] * (1.0f / 6.0f));
            MT_UVBuffer.push_back(0.0f);
            MT_UVBuffer.push_back((1.0f / 6.0f) + nametable.tiles[z] * (1.0f / 6.0f));
            MT_UVBuffer.push_back(1.0f);

            MT_UVBuffer.push_back((1.0f / 6.0f) + nametable.tiles[z] * (1.0f / 6.0f));
            MT_UVBuffer.push_back(1.0f);
            MT_UVBuffer.push_back(0.0f + nametable.tiles[z] * (1.0f / 6.0f));
            MT_UVBuffer.push_back(1.0f);
            MT_UVBuffer.push_back(0.0f + nametable.tiles[z] * (1.0f / 6.0f));
            MT_UVBuffer.push_back(0.0f);
            z++;
        }
    }


    glGenBuffers(1, &uv_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glBufferData(GL_ARRAY_BUFFER, MT_UVBuffer.size() * 4, MT_UVBuffer.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, MT_VertexBuffer.size() * 4, MT_VertexBuffer.data(), GL_STATIC_DRAW);


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

void Renderer::AddtoTileMap(Tile* tile, char position) {
    int overwrite_pos = (position * 16); //change overwrite_pos // + (y * width)
    for (int y = 0; y < 16; y++) {
        overwrite_pos = (position * 16) + y; //change overwrite_pos // + (y * width)
        for (int x = 0 + y; x < 256; x += 16) {
            TileMap[overwrite_pos] = tile->pixels[x];
            overwrite_pos += 96;
        }
    }

    for (int i = 0; i < 96 * 16; i++) {
        if (TileMap[i] == 1) {
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
    }

    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 96, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelcanvas.data());

    pixelcanvas.clear();
}

void Renderer::SetMaintables(Scene* scene) {
    glm::mat4 MVP = scene->GetCamera()->GetProMat() * scene->GetCamera()->GetCamMat();

    GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

   // for (int i = 0; i < 32 * 30; i++) 
    //}


        //MT_UVBuffer.push_back(0.0f);
        //MT_UVBuffer.push_back(0.0f);
        //MT_UVBuffer.push_back(0.167f * 32);
        //MT_UVBuffer.push_back(0.0f);
        //MT_UVBuffer.push_back(0.167f * 32);
        //MT_UVBuffer.push_back(1.0f * 30);

        //MT_UVBuffer.push_back(0.167f * 32);
        //MT_UVBuffer.push_back(1.0f * 30);
        //MT_UVBuffer.push_back(0.0f);
        //MT_UVBuffer.push_back(1.0f * 30);
        //MT_UVBuffer.push_back(0.0f);
        //MT_UVBuffer.push_back(0.0f);

  //  }

    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);

    GLuint vertexPositionID = glGetAttribLocation(shaderProgram, "vertexPosition");
    glEnableVertexAttribArray(vertexPositionID);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glVertexAttribPointer(
        vertexPositionID,   // attribute 0. No particular reason for 0, but must match the layout in the shader.
        2,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    GLuint uvPositionID = glGetAttribLocation(shaderProgram, "uvPosition");
    glEnableVertexAttribArray(uvPositionID);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glVertexAttribPointer(
        uvPositionID,   // attribute 0. No particular reason for 0, but must match the layout in the shader.
        2,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );
    glDrawArrays(GL_TRIANGLES, 0, MT_UVBuffer.size() / 2); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(vertexPositionID);
    glDisableVertexAttribArray(uvPositionID);
}

void Renderer::GenerateSprite(Entity* entity, char* canvas, char width, char height) {

    VertexBuffer[0] = -0.5f * width;
    VertexBuffer[1] = 0.5f * height;

    VertexBuffer[2] = 0.5f * width;
    VertexBuffer[3] = 0.5f * height;

    VertexBuffer[4] = 0.5f * width;
    VertexBuffer[5] = -0.5f * height;

    VertexBuffer[6] = 0.5f * width;
    VertexBuffer[7] = -0.5f * height;

    VertexBuffer[8] = -0.5f * width;
    VertexBuffer[9] = -0.5f * height;

    VertexBuffer[10] = -0.5f * width;
    VertexBuffer[11] = 0.5f * height;

    glGenBuffers(1, &entity->vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, entity->vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, (sizeof(VertexBuffer) / sizeof(VertexBuffer[0])) * 4, VertexBuffer, GL_STATIC_DRAW);

    glGenBuffers(1, &entity->uv_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, entity->uv_buffer);
    glBufferData(GL_ARRAY_BUFFER, (sizeof(UVBuffer) / sizeof(UVBuffer[0])) * 4, UVBuffer, GL_STATIC_DRAW);

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
        2,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    GLuint uvPositionID = glGetAttribLocation(shaderProgram, "uvPosition");
    glEnableVertexAttribArray(uvPositionID);
    glBindBuffer(GL_ARRAY_BUFFER, entity->uv_buffer);
    glVertexAttribPointer(
        uvPositionID,   // attribute 0. No particular reason for 0, but must match the layout in the shader.
        2,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );
    glDrawArrays(GL_TRIANGLES, 0, 6); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(vertexPositionID);
    glDisableVertexAttribArray(uvPositionID);
}
