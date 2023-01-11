#include "renderer.h"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <cmath>
#include <stdio.h>

const char* vertex_shader = "#version 330 core\n"
"layout(location = 0) in vec2 vertexPosition;\n"
"layout(location = 1) in vec2 uvPosition;\n"
"uniform mat4 MVP;\n"
"out vec2 UV;\n"
"void main()\n"
"{\n"
"	gl_Position = MVP * vec4(vertexPosition.x + 0.001f,vertexPosition.y + 0.001f,0.0f, 1.0f);\n"//+0.01f for wrapping
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
    MT_UVBuffer.resize(2880 * 4);
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

    for (int i = 0; i < 5 * 16 * 16; i++) {
        pixelcanvas.push_back(0);
        pixelcanvas.push_back(0);
        pixelcanvas.push_back(0);
        pixelcanvas.push_back(255);
    }

    for (int i = 0; i < 4; i++) {
        Maintables[i] = new Nametable();
    }

    glGenTextures(1, &tilemap_texture_buffer);
    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 5 * 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelcanvas.data());
    glGenerateMipmap(GL_TEXTURE_2D);

    pixelcanvas.clear();

    N = 0;
}

void Renderer::SetUpMaintable(Nametable** nametables, unsigned char RenderPos) {

    //Set-up maintables
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 240; i++) {
            Maintables[j]->tiles[i] = nametables[RenderPos + (j & 1)]->tiles[i];
            Maintables[j]->flip[i] = nametables[RenderPos + (j & 1)]->flip[i];
        }
    }

    int test = 0;
    for (N = 0; N < 4; N++) {
        int z = 0;
        for (int y = 0 + 15 * ((N >> 1) & 1); y < 15 + 15 * ((N >> 1) & 1); y++) {

            for (int x = 0 + 16 * (N & 1); x < 16 + 16 * (N & 1); x++) {
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

                //unsigned char flip = Maintables[N]->flip[z];
                //MT_UVBuffer.push_back(0.0f + (flip & 1) * (1.0f / 6.0f) + Maintables[N]->tiles[z] * (1.0f / 6.0f));
                //MT_UVBuffer.push_back(0.0f + ((flip >> 1) & 1));
                //MT_UVBuffer.push_back((1.0f / 6.0f) - (flip & 1) * (1.0f / 6.0f) + Maintables[N]->tiles[z] * (1.0f / 6.0f));
                //MT_UVBuffer.push_back(0.0f + ((flip >> 1) & 1));
                //MT_UVBuffer.push_back((1.0f / 6.0f) - (flip & 1) * (1.0f / 6.0f) + Maintables[N]->tiles[z] * (1.0f / 6.0f));
                //MT_UVBuffer.push_back(1.0f - ((flip >> 1) & 1));
                //MT_UVBuffer.push_back((1.0f / 6.0f) - (flip & 1) * (1.0f / 6.0f) + Maintables[N]->tiles[z] * (1.0f / 6.0f));
                //MT_UVBuffer.push_back(1.0f - ((flip >> 1) & 1));
                //MT_UVBuffer.push_back(0.0f + (flip & 1) * (1.0f / 6.0f) + Maintables[N]->tiles[z] * (1.0f / 6.0f));
                //MT_UVBuffer.push_back(1.0f - ((flip >> 1) & 1));
                //MT_UVBuffer.push_back(0.0f + (flip & 1) * (1.0f / 6.0f) + Maintables[N]->tiles[z] * (1.0f / 6.0f));
                //MT_UVBuffer.push_back(0.0f + ((flip >> 1) & 1));
                EditTile(z, test);
                z++;
                test++;
            }
        }
    }

    //int z = 0;
    //for (int y = 0; y < 30; y++) {
    //    for (int x = 0; x < 32; x++) {
    //        MT_VertexBuffer.push_back((-0.5f + x) * 16.0f);
    //        MT_VertexBuffer.push_back((0.5f - y) * 16.0f);
    //        MT_VertexBuffer.push_back((0.5f + x) * 16.0f);
    //        MT_VertexBuffer.push_back((0.5f - y) * 16.0f);
    //        MT_VertexBuffer.push_back((0.5f + x) * 16.0f);
    //        MT_VertexBuffer.push_back((-0.5f - y) * 16.0f);

    //        MT_VertexBuffer.push_back((0.5f + x) * 16.0f);
    //        MT_VertexBuffer.push_back((-0.5f - y) * 16.0f);
    //        MT_VertexBuffer.push_back((-0.5f + x) * 16.0f);
    //        MT_VertexBuffer.push_back((-0.5f - y) * 16.0f);
    //        MT_VertexBuffer.push_back((-0.5f + x) * 16.0f);
    //        MT_VertexBuffer.push_back((0.5f - y) * 16.0f);
    //    }
    //}

    glGenBuffers(1, &uv_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glBufferData(GL_ARRAY_BUFFER, MT_UVBuffer.size() * 4, MT_UVBuffer.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, MT_VertexBuffer.size() * 4, MT_VertexBuffer.data(), GL_STATIC_DRAW);

    N = 0;
}

void Renderer::EditTile(unsigned short tile, int test) {
    unsigned short stile = test * 12;
    unsigned char flip = Maintables[N]->flip[tile] & 1;

    MT_UVBuffer[stile + 0] =  (flip * 0.2f + Maintables[N]->tiles[tile] * (0.2f));
    MT_UVBuffer[stile + 2] = (!flip * 0.2f + Maintables[N]->tiles[tile] * (0.2f));
    MT_UVBuffer[stile + 4] = (!flip * 0.2f + Maintables[N]->tiles[tile] * (0.2f));
    MT_UVBuffer[stile + 6] = (!flip * 0.2f + Maintables[N]->tiles[tile] * (0.2f));
    MT_UVBuffer[stile + 8] =  (flip * 0.2f + Maintables[N]->tiles[tile] * (0.2f));
    MT_UVBuffer[stile +10] =  (flip * 0.2f + Maintables[N]->tiles[tile] * (0.2f));

    flip = Maintables[N]->flip[tile];
    (flip >>= 1) &= 1;

    MT_UVBuffer[stile + 1] =  flip;
    MT_UVBuffer[stile + 3] =  flip;
    MT_UVBuffer[stile + 5] = !flip;
    MT_UVBuffer[stile + 7] = !flip;
    MT_UVBuffer[stile + 9] = !flip;
    MT_UVBuffer[stile +11] =  flip;
}

void Renderer::UpdateMainTile(Nametable* nametable, unsigned short tile) {
    Maintables[N]->tiles[tile] = nametable->tiles[tile];
    Maintables[N]->flip[tile] = nametable->flip[tile];
    EditTile(tile, tile);
}

//void Renderer::ProcessTileQueue() {
//    while (it != TileQueue.end()) {
//        EditTile(*it);
//        TileQueue.remove(*it);
//        it = TileQueue.begin();
//    }
//}

void Renderer::RenderScene(Scene* scene) {
    scene->renderpos =((scene->GetCamera()->X + scene->GetCamera()->scrolldir.x * 256) >> 8) + (((scene->GetCamera()->Y + scene->GetCamera()->scrolldir.y * 256) >> 8) * 3);
    overwrite_pos.x = (scene->GetCamera()->X + scene->GetCamera()->scrolldir.x * 256) & 0x1ff;
    overwrite_pos.y = (scene->GetCamera()->Y + scene->GetCamera()->scrolldir.y * 256) & 0x1ff;
    N = ((overwrite_pos.x >> 8) & 1) + ((overwrite_pos.y >> 8) & 1) * 2;
    N &= scene->rendermode;

    overwrite_pos.x *= 0.0625f;
    overwrite_pos.x &= 0xf;

    overwrite_pos.y *= 0.0625f;
    overwrite_pos.y &= 0xf;

    //overwrite_posz *= 0.0625f;
    //overwrite_posz &= 0xf;
    //overwrite_pos.x += overwrite_pos.y * 16; //Key

    //printf("scene->GetCamera()->X: %d\n", scene->GetCamera()->X);
   // printf("overwrite_pos.x: %d\n", overwrite_pos.x);
   // printf("overwrite_pos.y: %d\n", overwrite_pos.y);
    //printf("overwrite_posz: %d\n", overwrite_posz);
   // printf("N: %d\n", N);
    //printf("scene->renderpos : %d\n", scene->renderpos);

    if (scene->rendermode == 1) {
        for (int x = overwrite_pos.x; x < 240; x += 16) {
            Maintables[N]->tiles[overwrite_pos.x] = scene->Nametables[scene->renderpos]->tiles[x];
            Maintables[N]->flip[overwrite_pos.x] = scene->Nametables[scene->renderpos]->flip[x];
            EditTile(overwrite_pos.x, overwrite_pos.x + 240 * N);

            Maintables[N + 2]->tiles[overwrite_pos.x] = scene->Nametables[scene->renderpos]->tiles[x];
            Maintables[N + 2]->flip[overwrite_pos.x] = scene->Nametables[scene->renderpos]->flip[x];
            EditTile(overwrite_pos.x, overwrite_pos.x + 240 * (N + 2));

            overwrite_pos.x += 16;
        }
    }
    else {
        for (int x = overwrite_pos.y * 16; x < 16 + overwrite_pos.y * 16; x++) {
            Maintables[N]->tiles[x] = scene->Nametables[scene->renderpos]->tiles[x];
            Maintables[N]->flip[x] = scene->Nametables[scene->renderpos]->flip[x];
            EditTile(x, x + 240 * N);
            Maintables[N + 1]->tiles[x] = scene->Nametables[scene->renderpos]->tiles[x];
            Maintables[N + 1]->flip[x] = scene->Nametables[scene->renderpos]->flip[x];
            EditTile(x, x + 240 * (N + 1));
        }
    }

    
  //printf("scene->GetCamera()->Y: %d\n", scene->GetCamera()->Y + 240);
  //printf("overwrite_pos.y: %d\n", overwrite_pos.y);
   //printf("scene->renderpos.x : %d\n", scene->renderpos);

    /*
   overwrite_pos *= 16;

    for (int x = 0; x < 16; x++) {
        printf("overwrite_pos: %d\n", overwrite_pos);
        Maintables[N]->tiles[overwrite_pos] = scene->Nametables[2]->tiles[overwrite_pos];
        Maintables[N]->flip[overwrite_pos] = scene->Nametables[2]->flip[overwrite_pos];
        EditTile(overwrite_pos, overwrite_pos + 240 * N);
        overwrite_pos++;
    }*/

    RenderMaintables(scene); //TODO implement int renderpos

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
            overwrite_pos += 5 * 16;
        }
    }

    for (int i = 0; i < 5 * 16 * 16; i++) {
        if (TileMap[i] == 1) {
            pixelcanvas.push_back(0);
            pixelcanvas.push_back(0);
            pixelcanvas.push_back(0);
            pixelcanvas.push_back(255);
        }
        else {
            pixelcanvas.push_back(255);
            pixelcanvas.push_back(255);
            pixelcanvas.push_back(255);
            pixelcanvas.push_back(255);
        }
    }

    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 5 * 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelcanvas.data());

    pixelcanvas.clear();
}

void Renderer::RenderMaintables(Scene* scene) {
    glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1), glm::vec3(-120.0f, 112.0f, 0.0f));

    glm::mat4 MVP = scene->GetCamera()->GetProMat() * scene->GetCamera()->GetCamMat() * TranslationMatrix;

    GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

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
    glBufferData(GL_ARRAY_BUFFER, MT_UVBuffer.size() * 4, MT_UVBuffer.data(), GL_STATIC_DRAW);
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
