#include "renderer.h"
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <SiroGen83/entity.h>
#include <SiroGen83/scene.h>
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

    FT_UVBuffer.resize(2880);
    FT_VertexBuffer.resize(2880);
    FT_PaletteBuffer.resize(2880);
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

    for (GLuint i = 1; i < 5; i++) {
        PaletteBuffer[0] = (i - 1);
        PaletteBuffer[1] = (i - 1);
        PaletteBuffer[2] = (i - 1);
        PaletteBuffer[3] = (i - 1);
        PaletteBuffer[4] = (i - 1);
        PaletteBuffer[5] = (i - 1);

        glGenBuffers(1, &i);
        glBindBuffer(GL_ARRAY_BUFFER, i);
        glBufferData(GL_ARRAY_BUFFER, (sizeof(PaletteBuffer) / sizeof(PaletteBuffer[0])) * 4, PaletteBuffer, GL_STATIC_DRAW);

    }
    for (float y = 0.0f; y < 2.0f; y++) {
        for (float x = 0.0f; x < 2.0f; x++) {
            GLuint uv_buffer = 0;
            UVBuffer[0] = 0.0f + x;
            UVBuffer[1] = 0.0f + y;
            UVBuffer[2] = 1.0f - x;
            UVBuffer[3] = 0.0f + y;
            UVBuffer[4] = 1.0f - x;
            UVBuffer[5] = 1.0f - y;
            UVBuffer[6] = 1.0f - x;
            UVBuffer[7] = 1.0f - y;
            UVBuffer[8] = 0.0f + x;
            UVBuffer[9] = 1.0f - y;
            UVBuffer[10]= 0.0f + x;
            UVBuffer[11]= 0.0f + y;

            glGenBuffers(1, &uv_buffer);
            glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
            glBufferData(GL_ARRAY_BUFFER, (sizeof(UVBuffer) / sizeof(UVBuffer[0])) * 4, UVBuffer, GL_STATIC_DRAW);

        }
    }

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
    glGenTextures(1, &bg_PaletteSampler);
    glBindTexture(GL_TEXTURE_1D, bg_PaletteSampler);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, 4 * 4, 0, GL_RGBA, GL_UNSIGNED_BYTE, (void*) 0);
    glUniform1i(glGetUniformLocation(shaderProgram, "myPaletteSampler"), 1);

    glActiveTexture(GL_TEXTURE1);
    glGenTextures(1, &fg_PaletteSampler);
    glBindTexture(GL_TEXTURE_1D, fg_PaletteSampler);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, 4 * 4, 0, GL_RGBA, GL_UNSIGNED_BYTE, (void*)0);
    glUniform1i(glGetUniformLocation(shaderProgram, "myPaletteSampler"), 1);

    glGenBuffers(1, &fuv_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, fuv_buffer);
    glBufferData(GL_ARRAY_BUFFER, FT_UVBuffer.size() * 4, FT_UVBuffer.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &fvertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, fvertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, FT_VertexBuffer.size() * 4, FT_VertexBuffer.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &fpalette_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, fpalette_buffer);
    glBufferData(GL_ARRAY_BUFFER, FT_PaletteBuffer.size() * 4, FT_PaletteBuffer.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &uv_buffer);
    glGenBuffers(1, &vertex_buffer);
    glGenBuffers(1, &palette_buffer);




    N = 0;
}

void Renderer::UpdateFloatTile(unsigned short tile) {
    unsigned short stile = tile * 12;
    unsigned char flip = (Floattable->attributes[tile] >> 2) & 1;
    unsigned char color = Floattable->attributes[tile] & 3;
    float MapSize = 1.0f / (TileMap.size() / 256.0f);

    FT_UVBuffer[stile + 0] =  (flip * MapSize + Floattable->tiles[tile] * (MapSize));
    FT_UVBuffer[stile + 2] = (!flip * MapSize + Floattable->tiles[tile] * (MapSize));
    FT_UVBuffer[stile + 4] = (!flip * MapSize + Floattable->tiles[tile] * (MapSize));
    FT_UVBuffer[stile + 6] = (!flip * MapSize + Floattable->tiles[tile] * (MapSize));
    FT_UVBuffer[stile + 8] =  (flip * MapSize + Floattable->tiles[tile] * (MapSize));
    FT_UVBuffer[stile + 10] = (flip * MapSize + Floattable->tiles[tile] * (MapSize));

    flip = Floattable->attributes[tile];
    (flip >>= 3) &= 1;

    FT_UVBuffer[stile + 1] = flip;
    FT_UVBuffer[stile + 3] = flip;
    FT_UVBuffer[stile + 5] = !flip;
    FT_UVBuffer[stile + 7] = !flip;
    FT_UVBuffer[stile + 9] = !flip;
    FT_UVBuffer[stile + 11] = flip;

    stile /= 2;

    FT_PaletteBuffer[stile + 0] = color;
    FT_PaletteBuffer[stile + 1] = color;
    FT_PaletteBuffer[stile + 2] = color;
    FT_PaletteBuffer[stile + 3] = color;
    FT_PaletteBuffer[stile + 4] = color;
    FT_PaletteBuffer[stile + 5] = color;
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

    fg_PaletteColors[4]  = ForgroundPalette[0].colors[0].r;
    fg_PaletteColors[5]  = ForgroundPalette[0].colors[0].g;
    fg_PaletteColors[6]  = ForgroundPalette[0].colors[0].b;
    fg_PaletteColors[8]  = ForgroundPalette[0].colors[1].r;
    fg_PaletteColors[9]  = ForgroundPalette[0].colors[1].g;
    fg_PaletteColors[10] = ForgroundPalette[0].colors[1].b;
    fg_PaletteColors[12] = ForgroundPalette[0].colors[2].r;
    fg_PaletteColors[13] = ForgroundPalette[0].colors[2].g;
    fg_PaletteColors[14] = ForgroundPalette[0].colors[2].b;

    fg_PaletteColors[20] = ForgroundPalette[1].colors[0].r;
    fg_PaletteColors[21] = ForgroundPalette[1].colors[0].g;
    fg_PaletteColors[22] = ForgroundPalette[1].colors[0].b;
    fg_PaletteColors[24] = ForgroundPalette[1].colors[1].r;
    fg_PaletteColors[25] = ForgroundPalette[1].colors[1].g;
    fg_PaletteColors[26] = ForgroundPalette[1].colors[1].b;
    fg_PaletteColors[28] = ForgroundPalette[1].colors[2].r;
    fg_PaletteColors[29] = ForgroundPalette[1].colors[2].g;
    fg_PaletteColors[30] = ForgroundPalette[1].colors[2].b;

    fg_PaletteColors[36] = ForgroundPalette[2].colors[0].r;
    fg_PaletteColors[37] = ForgroundPalette[2].colors[0].g;
    fg_PaletteColors[38] = ForgroundPalette[2].colors[0].b;
    fg_PaletteColors[40] = ForgroundPalette[2].colors[1].r;
    fg_PaletteColors[41] = ForgroundPalette[2].colors[1].g;
    fg_PaletteColors[42] = ForgroundPalette[2].colors[1].b;
    fg_PaletteColors[44] = ForgroundPalette[2].colors[2].r;
    fg_PaletteColors[45] = ForgroundPalette[2].colors[2].g;
    fg_PaletteColors[46] = ForgroundPalette[2].colors[2].b;

    fg_PaletteColors[52] = ForgroundPalette[3].colors[0].r;
    fg_PaletteColors[53] = ForgroundPalette[3].colors[0].g;
    fg_PaletteColors[54] = ForgroundPalette[3].colors[0].b;
    fg_PaletteColors[56] = ForgroundPalette[3].colors[1].r;
    fg_PaletteColors[57] = ForgroundPalette[3].colors[1].g;
    fg_PaletteColors[58] = ForgroundPalette[3].colors[1].b;
    fg_PaletteColors[60] = ForgroundPalette[3].colors[2].r;
    fg_PaletteColors[61] = ForgroundPalette[3].colors[2].g;
    fg_PaletteColors[62] = ForgroundPalette[3].colors[2].b;

    glBindTexture(GL_TEXTURE_1D, bg_PaletteSampler);
    glTexSubImage1D(GL_TEXTURE_1D, 0, 0, 4 * 4, GL_RGBA, GL_UNSIGNED_BYTE, bg_PaletteColors);

    glBindTexture(GL_TEXTURE_1D, fg_PaletteSampler);
    glTexSubImage1D(GL_TEXTURE_1D, 0, 0, 4 * 4, GL_RGBA, GL_UNSIGNED_BYTE, fg_PaletteColors);
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

void Renderer::SetFloattable(Nametable* nametable){
    Floattable = nametable;

    int z = 0;
    for (int y = 0; y < 15; y++) {

        for (int x = 0; x < 16; x++) {
            FT_VertexBuffer[(z * 12) + 0] = ((-0.5f + x) * 16.0f);
            FT_VertexBuffer[(z * 12) + 1] = ((0.5f - y) * 16.0f);
            FT_VertexBuffer[(z * 12) + 2] = ((0.5f + x) * 16.0f);
            FT_VertexBuffer[(z * 12) + 3] = ((0.5f - y) * 16.0f);
            FT_VertexBuffer[(z * 12) + 4] = ((0.5f + x) * 16.0f);
            FT_VertexBuffer[(z * 12) + 5] = ((-0.5f - y) * 16.0f);
            FT_VertexBuffer[(z * 12) + 6] = ((0.5f + x) * 16.0f);
            FT_VertexBuffer[(z * 12) + 7] = ((-0.5f - y) * 16.0f);
            FT_VertexBuffer[(z * 12) + 8] = ((-0.5f + x) * 16.0f);
            FT_VertexBuffer[(z * 12) + 9] = ((-0.5f - y) * 16.0f);
            FT_VertexBuffer[(z * 12) + 10] = ((-0.5f + x) * 16.0f);
            FT_VertexBuffer[(z * 12) + 11] = ((0.5f - y) * 16.0f);

            UpdateFloatTile(z);
            z++;
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER, fuv_buffer);
    glBufferData(GL_ARRAY_BUFFER, FT_UVBuffer.size() * 4, FT_UVBuffer.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, fvertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, FT_VertexBuffer.size() * 4, FT_VertexBuffer.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, fpalette_buffer);
    glBufferData(GL_ARRAY_BUFFER, FT_PaletteBuffer.size() * 4, FT_PaletteBuffer.data(), GL_STATIC_DRAW);

}

void Renderer::PlayAnimation(Entity* entity, Animation* animation, unsigned char endframe, unsigned char beginframe) {
    if (!entity->frame) {
        entity->frame = beginframe;
    }
    SetSpritetoEntity(entity, animation->sprites[entity->frame]); // PALETTE_FLAG_ZERO | FLIP_FLAG_HOR
    if (glfwGetTime() - entity->starttime > animation->framerate) {
        SetSpritetoEntity(entity, animation->sprites[entity->frame++]); // PALETTE_FLAG_ZERO | FLIP_FLAG_HOR

        if (entity->frame > endframe) {
            entity->frame = beginframe;
        }

        entity->starttime = glfwGetTime();
    }
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

    //if (rendermode == 1) {
    //
    //    N = (overwrite_pos.x >> 8) & 1;
    //    // printf("N: %d\n", N);
    //    overwrite_pos.x *= 0.0625f;
    //    overwrite_pos.x &= 0xf;
    //
    //    for (int x = overwrite_pos.x; x < 240; x += 16) {
    //        Maintables[N]->tiles[overwrite_pos.x] = scene->Nametables[scene->renderpos]->tiles[x];
    //        Maintables[N]->attributes[overwrite_pos.x] = scene->Nametables[scene->renderpos]->attributes[x];
    //        EditTile(overwrite_pos.x, overwrite_pos.x + 240 * N);
    //
    //        overwrite_pos.x += 16;
    //    }
    //}
    //else {
    //
    //    N = (overwrite_pos.y >> 8) & 1;
    //
    //    overwrite_pos.y *= 0.0625f;
    //    overwrite_pos.y &= 0xf;
    //
    //    for (int x = overwrite_pos.y * 16; x < 16 + overwrite_pos.y * 16; x++) {
    //        Maintables[N]->tiles[x] = scene->Nametables[scene->renderpos]->tiles[x];
    //        Maintables[N]->attributes[x] = scene->Nametables[scene->renderpos]->attributes[x];
    //        EditTile(x, x + 240 * N);
    //    }
    //}

    
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
    RenderFloattable(scene);

    for (Entity* it : scene->entities) {
        if (((it->position.y + scene->GetCamera()->scrolldir.y * 512) & 0x1ff) > 479) {
            it->position.y += -32 + scene->GetCamera()->scrolldir.y * 64;
        }
        glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1), glm::vec3((it->position.x & 511) - 120.001f, -(it->position.y & 511) + 112.001f, 0.0f));

        glm::mat4 MVP = scene->GetCamera()->GetProMat() * scene->GetCamera()->GetCamMat() * TranslationMatrix;

        GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        if (it->vertex_buffer) {
            RenderEntity(it);
        }
    }
}

void Renderer::AddSpritetoMemory(Sprite* sprite, GLuint position) {
    VertexBuffer[0] = 0.0f * sprite->width;
    VertexBuffer[1] = 1.0f * sprite->height;

    VertexBuffer[2] = 1.0f * sprite->width;
    VertexBuffer[3] = 1.0f * sprite->height;

    VertexBuffer[4] = 1.0f * sprite->width;
    VertexBuffer[5] = 0.0f * sprite->height;

    VertexBuffer[6] = 1.0f * sprite->width;
    VertexBuffer[7] = 0.0f * sprite->height;

    VertexBuffer[8] = 0.0f * sprite->width;
    VertexBuffer[9] = 0.0f * sprite->height;

    VertexBuffer[10] = 0.0f * sprite->width;
    VertexBuffer[11] = 1.0f * sprite->height;


    position += 5;

    glDeleteTextures(1, &position);

    position += 10;

    glDeleteBuffers(1, &position);


    glGenBuffers(1, &position);
    glBindBuffer(GL_ARRAY_BUFFER, position);
    glBufferData(GL_ARRAY_BUFFER, (sizeof(VertexBuffer) / sizeof(VertexBuffer[0])) * 4, VertexBuffer, GL_STATIC_DRAW);

    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &position);
    glBindTexture(GL_TEXTURE_2D, position);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, sprite->width, sprite->height, 0, GL_RED, GL_UNSIGNED_BYTE, sprite->pixels);
    glUniform1i(glGetUniformLocation(shaderProgram, "myTextureSampler"), 0);
}

void Renderer::SetSpritetoEntity(Entity* entity, GLuint position) {
    entity->texture_buffer = position + 4;
    entity->vertex_buffer = position + 15;
}

void Renderer::SetAttributetoEntity(Entity* entity, GLuint attribute) {
    entity->uv_buffer = (attribute >> 2) + 5;
    attribute &= 3;
    entity->palette_buffer = attribute + 1;
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
void Renderer::RenderFloattable(Scene* scene) {

    glm::mat4 fMVP = glm::scale(glm::mat4(1), glm::vec3(0.0078125f)) * glm::translate(glm::mat4(1), glm::vec3(-120.001f, 120.001f, 0.0f));

    GLuint fMatrixID = glGetUniformLocation(shaderProgram, "MVP");
    glUniformMatrix4fv(fMatrixID, 1, GL_FALSE, &fMVP[0][0]);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);
    glUniform1i(glGetUniformLocation(shaderProgram, "myTextureSampler"), 0);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_1D, bg_PaletteSampler);
    glUniform1i(glGetUniformLocation(shaderProgram, "myPaletteSampler"), 1);

    GLuint fvertexPositionID = glGetAttribLocation(shaderProgram, "vertexPosition");
    glEnableVertexAttribArray(fvertexPositionID);
    glBindBuffer(GL_ARRAY_BUFFER, fvertex_buffer);
    glVertexAttribPointer(
        fvertexPositionID,   // attribute 0. No particular reason for 0, but must match the layout in the shader.
        2,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    GLuint fuvPositionID = glGetAttribLocation(shaderProgram, "uvPosition");
    glEnableVertexAttribArray(fuvPositionID);
    glBindBuffer(GL_ARRAY_BUFFER, fuv_buffer);
    glBufferData(GL_ARRAY_BUFFER, FT_UVBuffer.size() * 4, FT_UVBuffer.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(
        fuvPositionID,       // attribute 0. No particular reason for 0, but must match the layout in the shader.
        2,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );
    GLuint fpaletteID = glGetAttribLocation(shaderProgram, "PaletteOffset");
    glEnableVertexAttribArray(fpaletteID);
    glBindBuffer(GL_ARRAY_BUFFER, fpalette_buffer);
    glVertexAttribPointer(
        fpaletteID,
        1,
        GL_FLOAT,
        GL_FALSE,
        0,
        (void*)0
    );
    glDrawArrays(GL_TRIANGLES, 0, FT_UVBuffer.size() / 2); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(fvertexPositionID);
    glDisableVertexAttribArray(fuvPositionID);
    glDisableVertexAttribArray(fpaletteID);
}


void Renderer::RenderMaintables(Scene* scene) {
    glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1), glm::vec3(-120.001f, 112.001f, 0.0f));

    glm::mat4 MVP = scene->GetCamera()->GetProMat() * scene->GetCamera()->GetCamMat() * TranslationMatrix;

    GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);
    glUniform1i(glGetUniformLocation(shaderProgram, "myTextureSampler"), 0);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_1D, bg_PaletteSampler);
    glUniform1i(glGetUniformLocation(shaderProgram, "myPaletteSampler"), 1);

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
        uvPositionID,       // attribute 0. No particular reason for 0, but must match the layout in the shader.
        2,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );
    GLuint paletteID = glGetAttribLocation(shaderProgram, "PaletteOffset");
    glEnableVertexAttribArray(paletteID);
    glBindBuffer(GL_ARRAY_BUFFER, palette_buffer);
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

void Renderer::RenderEntity(Entity* entity) {

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, entity->texture_buffer);
    glUniform1i(glGetUniformLocation(shaderProgram, "myTextureSampler"), 0);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_1D, fg_PaletteSampler);
    glUniform1i(glGetUniformLocation(shaderProgram, "myPaletteSampler"), 1);

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
    GLuint paletteID = glGetAttribLocation(shaderProgram, "PaletteOffset");
    glEnableVertexAttribArray(paletteID);
    glBindBuffer(GL_ARRAY_BUFFER, entity->palette_buffer);
    glVertexAttribPointer(
        paletteID,
        1,
        GL_FLOAT,
        GL_FALSE,
        0,
        (void*)0
    );
    glDrawArrays(GL_TRIANGLES, 0, 6); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(vertexPositionID);
    glDisableVertexAttribArray(uvPositionID);
    glDisableVertexAttribArray(paletteID);
}
