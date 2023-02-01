#include "renderer.h"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <cmath>
#include <stdio.h>

const char* vertex_shader = 
"#version 330 core\n"
"layout(location = 0) in vec2 vertexPosition;\n"
"layout(location = 1) in vec2 uvPosition;\n"
"layout(location = 2) in float PaletteOffset;\n"
"uniform mat4 MVP;\n"
"out vec2 UV;\n"
"out float PL;\n"
"void main()\n"
"{\n"
"	gl_Position = MVP * vec4(vertexPosition.x ,vertexPosition.y,0.0f, 1.0f);\n"
"	UV = uvPosition;\n"
"	PL = PaletteOffset;\n"
"};\0";

const char* fragment_shader = 
"#version 330 core\n"
"in vec2 UV;\n"
"in float PL;\n"
"out vec4 FragColor;\n"
"uniform sampler2D myTextureSampler;\n"
"uniform sampler1D myPaletteSampler;\n"
"void main()\n"
"{\n"
"	float index = texture2D(myTextureSampler, UV).r;\n"
"   vec4 texel = texelFetch(myPaletteSampler, int(index * 255 + PL * 4), 0);\n"
"	FragColor = texel;\n"
"};\0";

Renderer* Renderer::_instance = 0;

Renderer::Renderer() {
    //Setup Maintables
    MT_UVBuffer.resize(2880 * 2);
    MT_VertexBuffer.resize(2880 * 2);
    MT_PaletteBuffer.resize(2880);
    TileMap.resize(256 * 16 * 16);

    //Initialize forground and background palettes
    unsigned char PaletteColors[] = {
        0,0,0,0,    0,0,0,255,  0,0,0,255,  0,0,0,255,
        0,0,0,0,    0,0,0,255,  0,0,0,255,  0,0,0,255,
        0,0,0,0,    0,0,0,255,  0,0,0,255,  0,0,0,255,
        0,0,0,0,    0,0,0,255,  0,0,0,255,  0,0,0,255,
    };
    for (int i = 0; i < 64; i++) {
        bg_PaletteColors[i] = PaletteColors[i];
        fg_PaletteColors[i] = PaletteColors[i];
    }

    //Shader stuff
    //GLint Result = GL_FALSE;
    //int InfoLogLength;


    // Compile Vertex Shader
    GLuint VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VertexShader, 1, &vertex_shader, nullptr);
    glCompileShader(VertexShader);

    // Check Vertex Shader
    //glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &Result);
    //glGetShaderiv(VertexShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
    //if (InfoLogLength > 0) {
    //    std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
    //    glGetShaderInfoLog(VertexShader, InfoLogLength, nullptr, &VertexShaderErrorMessage[0]);
    //    printf("%s", &VertexShaderErrorMessage[0]);
    //}

    // Compile Fragment Shader
    GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FragmentShader, 1, &fragment_shader, nullptr);
    glCompileShader(FragmentShader);

    // Check Fragment Shader
    //glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &Result);
    //glGetShaderiv(FragmentShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
    //if (InfoLogLength > 0) {
    //    std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
    //    glGetShaderInfoLog(FragmentShader, InfoLogLength, nullptr, &FragmentShaderErrorMessage[0]);
    //    printf("%s", &FragmentShaderErrorMessage[0]);
    //}

    // Link the program
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, VertexShader);
    glAttachShader(shaderProgram, FragmentShader);
    glLinkProgram(shaderProgram);

    // Check the program
    //glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Result);
    //glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &InfoLogLength);
    //if (InfoLogLength > 0) {
    //    std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
    //    glGetProgramInfoLog(shaderProgram, InfoLogLength, nullptr, &ProgramErrorMessage[0]);
    //    printf("%s", &ProgramErrorMessage[0]);
    //}

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

    for (int i = 0; i < 2; i++) {
        Maintables[i] = new Nametable();
    }

    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &tilemap_texture_buffer);
    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, TileMap.size() / 16, 16, 0, GL_RED, GL_UNSIGNED_BYTE, (void*)0);
    glUniform1i(glGetUniformLocation(shaderProgram, "myTextureSampler"), 0);

    glActiveTexture(GL_TEXTURE1);
    glGenTextures(1, &PaletteSampler);
    glBindTexture(GL_TEXTURE_1D, PaletteSampler);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, 4 * 4, 0, GL_RGBA, GL_UNSIGNED_BYTE, (void*) 0);
    glUniform1i(glGetUniformLocation(shaderProgram, "myPaletteSampler"), 1);

    glGenBuffers(1, &uv_buffer);
    glGenBuffers(1, &vertex_buffer);
    glGenBuffers(1, &palette_buffer);

    N = 0;
}

void Renderer::EditTile(unsigned short tile, int test) {
    unsigned short stile = test * 12;
    unsigned char flip = (Maintables[N]->attributes[tile] >> 2) & 1;
    unsigned char color = Maintables[N]->attributes[tile] & 3;
    float MapSize = 1.0f / (TileMap.size() / 256.0f);

    MT_UVBuffer[stile + 0] =  (flip * MapSize + Maintables[N]->tiles[tile] * (MapSize));
    MT_UVBuffer[stile + 2] = (!flip * MapSize + Maintables[N]->tiles[tile] * (MapSize));
    MT_UVBuffer[stile + 4] = (!flip * MapSize + Maintables[N]->tiles[tile] * (MapSize));
    MT_UVBuffer[stile + 6] = (!flip * MapSize + Maintables[N]->tiles[tile] * (MapSize));
    MT_UVBuffer[stile + 8] =  (flip * MapSize + Maintables[N]->tiles[tile] * (MapSize));
    MT_UVBuffer[stile +10] =  (flip * MapSize + Maintables[N]->tiles[tile] * (MapSize));

    flip = Maintables[N]->attributes[tile];
    (flip >>= 3) &= 1;

    MT_UVBuffer[stile + 1] =  flip;
    MT_UVBuffer[stile + 3] =  flip;
    MT_UVBuffer[stile + 5] = !flip;
    MT_UVBuffer[stile + 7] = !flip;
    MT_UVBuffer[stile + 9] = !flip;
    MT_UVBuffer[stile +11] =  flip;

    stile /= 2;

    MT_PaletteBuffer[stile + 0] = color;
    MT_PaletteBuffer[stile + 1] = color;
    MT_PaletteBuffer[stile + 2] = color;
    MT_PaletteBuffer[stile + 3] = color;
    MT_PaletteBuffer[stile + 4] = color;
    MT_PaletteBuffer[stile + 5] = color;
}

void Renderer::UpdateMainTile(Nametable* nametable, unsigned short tile) {
    Maintables[N]->tiles[tile] = nametable->tiles[tile];
    Maintables[N]->attributes[tile] = nametable->attributes[tile];
    EditTile(tile, tile);
}

void Renderer::UpdatePalettes() {

    bg_PaletteColors[4]  = BackgroundPalette[0].colors[0].r;
    bg_PaletteColors[5]  = BackgroundPalette[0].colors[0].g;
    bg_PaletteColors[6]  = BackgroundPalette[0].colors[0].b;

    bg_PaletteColors[8]  = BackgroundPalette[0].colors[1].r;
    bg_PaletteColors[9]  = BackgroundPalette[0].colors[1].g;
    bg_PaletteColors[10] = BackgroundPalette[0].colors[1].b;

    bg_PaletteColors[12] = BackgroundPalette[0].colors[2].r;
    bg_PaletteColors[13] = BackgroundPalette[0].colors[2].g;
    bg_PaletteColors[14] = BackgroundPalette[0].colors[2].b;

    bg_PaletteColors[20] = BackgroundPalette[1].colors[0].r;
    bg_PaletteColors[21] = BackgroundPalette[1].colors[0].g;
    bg_PaletteColors[22] = BackgroundPalette[1].colors[0].b;

    bg_PaletteColors[24] = BackgroundPalette[1].colors[1].r;
    bg_PaletteColors[25] = BackgroundPalette[1].colors[1].g;
    bg_PaletteColors[26] = BackgroundPalette[1].colors[1].b;

    bg_PaletteColors[28] = BackgroundPalette[1].colors[2].r;
    bg_PaletteColors[29] = BackgroundPalette[1].colors[2].g;
    bg_PaletteColors[30] = BackgroundPalette[1].colors[2].b;

    bg_PaletteColors[36] = BackgroundPalette[2].colors[0].r;
    bg_PaletteColors[37] = BackgroundPalette[2].colors[0].g;
    bg_PaletteColors[38] = BackgroundPalette[2].colors[0].b;

    bg_PaletteColors[40] = BackgroundPalette[2].colors[1].r;
    bg_PaletteColors[41] = BackgroundPalette[2].colors[1].g;
    bg_PaletteColors[42] = BackgroundPalette[2].colors[1].b;

    bg_PaletteColors[44] = BackgroundPalette[2].colors[2].r;
    bg_PaletteColors[45] = BackgroundPalette[2].colors[2].g;
    bg_PaletteColors[46] = BackgroundPalette[2].colors[2].b;

    bg_PaletteColors[52] = BackgroundPalette[3].colors[0].r;
    bg_PaletteColors[53] = BackgroundPalette[3].colors[0].g;
    bg_PaletteColors[54] = BackgroundPalette[3].colors[0].b;

    bg_PaletteColors[56] = BackgroundPalette[3].colors[1].r;
    bg_PaletteColors[57] = BackgroundPalette[3].colors[1].g;
    bg_PaletteColors[58] = BackgroundPalette[3].colors[1].b;

    bg_PaletteColors[60] = BackgroundPalette[3].colors[2].r;
    bg_PaletteColors[61] = BackgroundPalette[3].colors[2].g;
    bg_PaletteColors[62] = BackgroundPalette[3].colors[2].b;

    glBindTexture(GL_TEXTURE_1D, PaletteSampler);
    glTexSubImage1D(GL_TEXTURE_1D, 0, 0, 4 * 4, GL_RGBA, GL_UNSIGNED_BYTE, bg_PaletteColors);
}

void Renderer::SetRenderMode(Scene* scene, unsigned char mode) {
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 240; i++) {
            Maintables[j]->tiles[i] = scene->Nametables[scene->renderpos + (j)]->tiles[i];
            Maintables[j]->attributes[i] = scene->Nametables[scene->renderpos + (j)]->attributes[i];
        }
    }

    int i = 0;
    if (mode == 1) {//when running in mode 2
        for (N = 0; N < 2; N++) {
            int z = 0;
            for (int y = 0; y < 15; y++) {

                for (int x = 0 + 16 * N; x < 16 + 16 * N; x++) {
                    MT_VertexBuffer[(i * 12) + 0] = ((-0.5f + x) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 1] = ((0.5f - y) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 2] = ((0.5f + x) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 3] = ((0.5f - y) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 4] = ((0.5f + x) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 5] = ((-0.5f - y) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 6] = ((0.5f + x) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 7] = ((-0.5f - y) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 8] = ((-0.5f + x) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 9] = ((-0.5f - y) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 10] = ((-0.5f + x) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 11] = ((0.5f - y) * 16.0f);

                    EditTile(z, i);
                    z++;
                    i++;
                }
            }
        }
        if (((scene->GetCamera()->Y + scene->GetCamera()->scrolldir.y * 256) & 0xff) > 239) {
            scene->GetCamera()->Y += -16 + scene->GetCamera()->scrolldir.y * 32;
        }
        scene->GetCamera()->scrolldir.y = (scene->GetCamera()->Y >> 8) & 1;
        scene->GetCamera()->Y = 0 + 512 * (scene->GetCamera()->Y >> 9);
    }
    else {//set rendermode to 2
        for (N = 0; N < 2; N++) {
            int z = 0;
            for (int y = 0 + 15 * N; y < 15 + 15 * N; y++) {

                for (int x = 0; x < 16; x++) {
                    MT_VertexBuffer[(i * 12) + 0] = ((-0.5f + x) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 1] = ((0.5f - y) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 2] = ((0.5f + x) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 3] = ((0.5f - y) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 4] = ((0.5f + x) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 5] = ((-0.5f - y) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 6] = ((0.5f + x) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 7] = ((-0.5f - y) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 8] = ((-0.5f + x) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 9] = ((-0.5f - y) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 10] = ((-0.5f + x) * 16.0f);
                    MT_VertexBuffer[(i * 12) + 11] = ((0.5f - y) * 16.0f);

                    EditTile(z, i);
                    z++;
                    i++;
                }
            }
        }
        //scene->GetCamera()->Y = scene->GetCamera()->X;
        scene->GetCamera()->scrolldir.x = (scene->GetCamera()->X >> 8) & 1;
        scene->GetCamera()->X = 0 + 512 * (scene->GetCamera()->X >> 9);
    }

    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glBufferData(GL_ARRAY_BUFFER, MT_UVBuffer.size() * 4, MT_UVBuffer.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, MT_VertexBuffer.size() * 4, MT_VertexBuffer.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, palette_buffer);
    glBufferData(GL_ARRAY_BUFFER, MT_PaletteBuffer.size() * 4, MT_PaletteBuffer.data(), GL_STATIC_DRAW);

    rendermode = mode;
}

//void Renderer::ProcessTileQueue() {
//    while (it != TileQueue.end()) {
//        EditTile(*it);
//        TileQueue.remove(*it);
//        it = TileQueue.begin();
//    }
//}

void Renderer::RenderScene(Scene* scene) {
    scene->renderpos=((scene->GetCamera()->X + scene->GetCamera()->scrolldir.x * 256) >> 8) + (((scene->GetCamera()->Y + scene->GetCamera()->scrolldir.y * 256) >> 8) * 3);
    overwrite_pos.x = (scene->GetCamera()->X + scene->GetCamera()->scrolldir.x * 256) & 0x1ff;
    overwrite_pos.y = (scene->GetCamera()->Y + scene->GetCamera()->scrolldir.y * 256) & 0x1ff;
    //overwrite_posz *= 0.0625f;
    //overwrite_posz &= 0xf;
    //overwrite_pos.x += overwrite_pos.y * 16; //Key

    //printf("scene->GetCamera()->X: %d\n", scene->GetCamera()->X);
    //printf("overwrite_pos.x: %d\n", overwrite_pos.x);
    //printf("overwrite_pos.y: %d\n", overwrite_pos.y);
    //printf("overwrite_posz: %d\n", overwrite_posz);
    //printf("scene->renderpos : %d\n", scene->renderpos);
    //printf("scene->GetCamera()->X: %d\n", scene->GetCamera()->X >> 8);
    //printf("scene->GetCamera()->Y: %d\n", scene->GetCamera()->Y >> 8);

    if (rendermode == 1) {

        N = (overwrite_pos.x >> 8) & 1;
        // printf("N: %d\n", N);
        overwrite_pos.x *= 0.0625f;
        overwrite_pos.x &= 0xf;

        for (int x = overwrite_pos.x; x < 240; x += 16) {
            Maintables[N]->tiles[overwrite_pos.x] = scene->Nametables[scene->renderpos]->tiles[x];
            Maintables[N]->attributes[overwrite_pos.x] = scene->Nametables[scene->renderpos]->attributes[x];
            EditTile(overwrite_pos.x, overwrite_pos.x + 240 * N);

            overwrite_pos.x += 16;
        }
    }
    else {

        N = (overwrite_pos.y >> 8) & 1;

        overwrite_pos.y *= 0.0625f;
        overwrite_pos.y &= 0xf;

        for (int x = overwrite_pos.y * 16; x < 16 + overwrite_pos.y * 16; x++) {
            Maintables[N]->tiles[x] = scene->Nametables[scene->renderpos]->tiles[x];
            Maintables[N]->attributes[x] = scene->Nametables[scene->renderpos]->attributes[x];
            EditTile(x, x + 240 * N);
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

       // GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
        //glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        //if (it->vertex_buffer) {
        //    RenderEntity(it);
        //}
    }
}

void Renderer::AddtoTileMap(Tile* tile, char position) {
    //TileMap.resize(512/*TileMap.size() + 16 * 16*/);
    int overwrite_pos = (position * 16); //change overwrite_pos // + (y * width)
    for (int y = 0; y < 16; y++) {
        overwrite_pos = (position * 16) + y; //change overwrite_pos // + (y * width)
        for (int x = 0 + y; x < 256; x += 16) {
            TileMap[overwrite_pos] = tile->pixels[x];
            overwrite_pos += (TileMap.size() / 256) * 16;
        }
    }

    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);
    //glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, TileMap.size() / 16, 16, 0, GL_RED, GL_UNSIGNED_BYTE, TileMap.data());
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, TileMap.size() / 16, 16, GL_RED, GL_UNSIGNED_BYTE, TileMap.data());
}

void Renderer::RenderMaintables(Scene* scene) {
    glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1), glm::vec3(-120.001f, 112.001f, 0.0f));

    glm::mat4 MVP = scene->GetCamera()->GetProMat() * scene->GetCamera()->GetCamMat() * TranslationMatrix;

    GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    //glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);
    //glUniform1i(glGetUniformLocation(shaderProgram, "myTextureSampler"), 0);
    //
    //glActiveTexture(GL_TEXTURE1);
    //glBindTexture(GL_TEXTURE_1D, PaletteSampler);
    //glUniform1i(glGetUniformLocation(shaderProgram, "myPaletteSampler"), 1);


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
    GLuint paletteID = glGetAttribLocation(shaderProgram, "PaletteOffset");
    glEnableVertexAttribArray(paletteID);
    glBindBuffer(GL_ARRAY_BUFFER, palette_buffer);
    glBufferData(GL_ARRAY_BUFFER, MT_PaletteBuffer.size() * 4, MT_PaletteBuffer.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(
        paletteID,
        1,
        GL_FLOAT,
        GL_FALSE,
        0,
        (void*)0
    );
    glDrawArrays(GL_TRIANGLES, 0, MT_UVBuffer.size() / 2); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(vertexPositionID);
    glDisableVertexAttribArray(uvPositionID);
    glDisableVertexAttribArray(paletteID);
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
        pixelcanvas.push_back(canvas[i]);
    }

    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &entity->texture_buffer);
    glBindTexture(GL_TEXTURE_2D, entity->texture_buffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, pixelcanvas.data());
    glUniform1i(glGetUniformLocation(shaderProgram, "myTextureSampler"), 0);

    pixelcanvas.clear();
}

void Renderer::RenderEntity(Entity* entity) {
    //glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, entity->texture_buffer);
   // glUniform1i(glGetUniformLocation(shaderProgram, "myTextureSampler"), 0);

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
