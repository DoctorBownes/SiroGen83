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
"uniform mat4 MVP;\n"
"out vec2 UV;\n"
"void main()\n"
"{\n"
"	gl_Position = MVP * vec4(vertexPosition.x ,vertexPosition.y,0.0f, 1.0f);\n"
"	UV = uvPosition;\n"
"};\0";

const char* fragment_shader = 
"#version 330 core\n"
"in vec2 UV;\n"
"out vec4 FragColor;\n"
"uniform sampler2D myTextureSampler;\n"
"uniform sampler1D myPaletteSampler;\n"
"void main()\n"
"{\n"
"	float index = texture2D(myTextureSampler, UV).r;\n"
"   vec4 texel = texelFetch(myPaletteSampler, int(index * 255), 0);\n"
"	FragColor = texel;\n"
"};\0";

Renderer* Renderer::_instance = 0;

Renderer::Renderer() {
    VertexBuffer[0] = 0.0f;
    VertexBuffer[1] = 0.0f;
    VertexBuffer[2] = 0.0f;
    VertexBuffer[3] = 0.0f;
    VertexBuffer[4] = 0.0f;
    VertexBuffer[5] = 0.0f;
    VertexBuffer[6] = 0.0f;
    VertexBuffer[7] = 0.0f;
    VertexBuffer[8] = 0.0f;
    VertexBuffer[9] = 0.0f;
    VertexBuffer[10] = 0.0f;
    VertexBuffer[11] = 0.0f;
    //Setup Maintables

    TileMap.resize(256 * 8 * 8);
    MapSize = 1.0f / (TileMap.size() / 64.0f);

    //Initialize forground and background palettes
    unsigned char tPaletteColors[] = {
        0,0,0,0,    0,0,0,255,  0,0,0,255,  0,0,0,255,
        0,0,0,255,    0,0,0,255,  0,0,0,255,  0,0,0,255,
        0,0,0,255,    0,0,0,255,  0,0,0,255,  0,0,0,255,
        0,0,0,255,    0,0,0,255,  0,0,0,255,  0,0,0,255,
        0,0,0,255,    0,0,0,255,  0,0,0,255,  0,0,0,255,
        0,0,0,255,    0,0,0,255,  0,0,0,255,  0,0,0,255,
        0,0,0,255,    0,0,0,255,  0,0,0,255,  0,0,0,255,
        0,0,0,255,    0,0,0,255,  0,0,0,255,  0,0,0,255,
    };
    for (int i = 0; i < 128; i++) {
        PaletteColors[i] = tPaletteColors[i];
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

    for (GLuint i = 1; i < 2; i++) {
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

    for (int i = 0; i < 4; i++) {
        MainScreen[i] = new TileScreen();
    }

    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &tilemap_texture_buffer);
    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, TileMap.size() / 8, 8, 0, GL_RED, GL_UNSIGNED_BYTE, (void*)0);
    glUniform1i(glGetUniformLocation(shaderProgram, "myTextureSampler"), 0);

    glActiveTexture(GL_TEXTURE1);
    glGenTextures(1, &bg_PaletteSampler);
    glBindTexture(GL_TEXTURE_1D, bg_PaletteSampler);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, 1 * 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, (void*) 0);
    glUniform1i(glGetUniformLocation(shaderProgram, "myPaletteSampler"), 1);

    glGenBuffers(1, &fuv_buffer);

    glGenBuffers(1, &uv_buffer);
    glGenBuffers(1, &vertex_buffer);
    glGenBuffers(1, &palette_buffer);


    N = 0;
}

void Renderer::UpdateGUITile(unsigned short tile) {
    unsigned short bigpos = (tile * 2 - (tile & 15)) * 2;
    unsigned short stile = (bigpos) * 12;
    unsigned short flip = (GUIScreen->attributes[tile] & 3) & 1;

    GUI_UVBuffer[stile + 0] = (flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 2] = (!flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 4] = (!flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 6] = (!flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 8] = (flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 10] = (flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));

    GUI_UVBuffer[stile + 1] = flip;
    GUI_UVBuffer[stile + 3] = flip;
    GUI_UVBuffer[stile + 5] = !flip;
    GUI_UVBuffer[stile + 7] = !flip;
    GUI_UVBuffer[stile + 9] = !flip;
    GUI_UVBuffer[stile + 11] = flip;

    bigpos += 1;
    stile = (bigpos) * 12;

    GUI_UVBuffer[stile + 0] = (flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 2] = (!flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 4] = (!flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 6] = (!flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 8] = (flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 10] = (flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));

    GUI_UVBuffer[stile + 1] = flip;
    GUI_UVBuffer[stile + 3] = flip;
    GUI_UVBuffer[stile + 5] = !flip;
    GUI_UVBuffer[stile + 7] = !flip;
    GUI_UVBuffer[stile + 9] = !flip;
    GUI_UVBuffer[stile + 11] = flip;

    bigpos += 31;
    stile = (bigpos) * 12;

    GUI_UVBuffer[stile + 0] = (flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 2] = (!flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 4] = (!flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 6] = (!flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 8] = (flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 10] = (flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));

    GUI_UVBuffer[stile + 1] = flip;
    GUI_UVBuffer[stile + 3] = flip;
    GUI_UVBuffer[stile + 5] = !flip;
    GUI_UVBuffer[stile + 7] = !flip;
    GUI_UVBuffer[stile + 9] = !flip;
    GUI_UVBuffer[stile + 11] = flip;

    bigpos += 1;
    stile = (bigpos) * 12;

    GUI_UVBuffer[stile + 0] = (flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 2] = (!flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 4] = (!flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 6] = (!flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 8] = (flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));
    GUI_UVBuffer[stile + 10] = (flip * MapSize + GUIScreen->tiles[bigpos] * (MapSize));

    GUI_UVBuffer[stile + 1] = flip;
    GUI_UVBuffer[stile + 3] = flip;
    GUI_UVBuffer[stile + 5] = !flip;
    GUI_UVBuffer[stile + 7] = !flip;
    GUI_UVBuffer[stile + 9] = !flip;
    GUI_UVBuffer[stile + 11] = flip;
}

void Renderer::EditTile(unsigned short tile) {
    unsigned short bigpos = (tile * 2 - (tile & 15)) * 2;
    unsigned short stile = (bigpos) * 12;
    unsigned short flip = (MainScreen[N]->attributes[tile] & 3) & 1;

    MT_UVBuffer[N][stile + 0] = (flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 2] = (!flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 4] = (!flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 6] = (!flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 8] = (flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 10] = (flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));


    MT_UVBuffer[N][stile + 1] = flip;
    MT_UVBuffer[N][stile + 3] = flip;
    MT_UVBuffer[N][stile + 5] = !flip;
    MT_UVBuffer[N][stile + 7] = !flip;
    MT_UVBuffer[N][stile + 9] = !flip;
    MT_UVBuffer[N][stile + 11] = flip;

    bigpos += 1;
    stile = (bigpos) * 12;

    MT_UVBuffer[N][stile + 0] = (flip * MapSize + MainScreen[N]->tiles [bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 2] = (!flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 4] = (!flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 6] = (!flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 8] = (flip * MapSize + MainScreen[N]->tiles [bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 10] = (flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));


    MT_UVBuffer[N][stile + 1] = flip;
    MT_UVBuffer[N][stile + 3] = flip;
    MT_UVBuffer[N][stile + 5] = !flip;
    MT_UVBuffer[N][stile + 7] = !flip;
    MT_UVBuffer[N][stile + 9] = !flip;
    MT_UVBuffer[N][stile + 11] = flip;

    bigpos += 31;
    stile = (bigpos) * 12;

    MT_UVBuffer[N][stile + 0] = (flip * MapSize + MainScreen[N]->tiles [bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 2] = (!flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 4] = (!flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 6] = (!flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 8] = (flip * MapSize + MainScreen[N]->tiles [bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 10] = (flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));


    MT_UVBuffer[N][stile + 1] = flip;
    MT_UVBuffer[N][stile + 3] = flip;
    MT_UVBuffer[N][stile + 5] = !flip;
    MT_UVBuffer[N][stile + 7] = !flip;
    MT_UVBuffer[N][stile + 9] = !flip;
    MT_UVBuffer[N][stile + 11] = flip;

    bigpos += 1;
    stile = (bigpos) * 12;

    MT_UVBuffer[N][stile + 0] = (flip * MapSize + MainScreen[N]->tiles [bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 2] = (!flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 4] = (!flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 6] = (!flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 8] = (flip * MapSize + MainScreen[N]->tiles [bigpos] * (MapSize));
    MT_UVBuffer[N][stile + 10] = (flip * MapSize + MainScreen[N]->tiles[bigpos] * (MapSize));


    MT_UVBuffer[N][stile + 1] = flip;
    MT_UVBuffer[N][stile + 3] = flip;
    MT_UVBuffer[N][stile + 5] = !flip;
    MT_UVBuffer[N][stile + 7] = !flip;
    MT_UVBuffer[N][stile + 9] = !flip;
    MT_UVBuffer[N][stile + 11] = flip;
}

void Renderer::UpdateMainTile(TileScreen* tilescreen, unsigned short tile) {
    unsigned short smallpos = (((tile - 32) & 31) + (tile / 64) * 32) / 2;
    N = (lo_CamX >> 8) | (lo_CamY >> 8) * 2;
    MainScreen[N]->tiles[tile] = tilescreen->tiles[tile];
    MainScreen[N]->attributes[smallpos] = tilescreen->attributes[smallpos];
    EditTile(smallpos);
}

void Renderer::UpdatePalettes() {

    int i = 4;
    int j = 0;
    while (i < 128) {
        PaletteColors[i] = MainPalette.colors[j].r;
        i++;
        PaletteColors[i] = MainPalette.colors[j].g;
        i++;
        PaletteColors[i] = MainPalette.colors[j].b;
        i++;
        i++;
        j++;
    }

    glBindTexture(GL_TEXTURE_1D, bg_PaletteSampler);
    glTexSubImage1D(GL_TEXTURE_1D, 0, 0, 1 * 32, GL_RGBA, GL_UNSIGNED_BYTE, PaletteColors);

}

void Renderer::SetRenderMode(Scene* scene) {
    for (int j = 0; j < 1; j++) {
        for (int i = 0; i < 960; i++) {
            MainScreen[j]->tiles[i] = scene->TileScreens[scene->renderpos + (j)]->tiles[i];
           // MainScreen[j]->attributes[i] = scene->TileScreens[scene->renderpos + (j)]->attributes[i];
        }
    }

    for (int j = 0; j < 1; j++) {
        for (int i = 0; i < 240; i++) {
            MainScreen[j]->attributes[i] = scene->TileScreens[scene->renderpos + (j)]->attributes[i];
        }
    }

    int i = 0;
    for (N = 0; N < 4; N++) {
        for (int y = 0; y < 30; y++) {
            for (int x = 0 + 32 * N; x < 32 + 32 * N; x++) {
                MT_VertexBuffer[0][(i * 12) + 0] =((-0.5f + x) * 8.0f);
                MT_VertexBuffer[0][(i * 12) + 1] = ((0.5f - y) * 8.0f);
                MT_VertexBuffer[0][(i * 12) + 2] = ((0.5f + x) * 8.0f);
                MT_VertexBuffer[0][(i * 12) + 3] = ((0.5f - y) * 8.0f);
                MT_VertexBuffer[0][(i * 12) + 4] = ((0.5f + x) * 8.0f);
                MT_VertexBuffer[0][(i * 12) + 5] =((-0.5f - y) * 8.0f);
                MT_VertexBuffer[0][(i * 12) + 6] = ((0.5f + x) * 8.0f);
                MT_VertexBuffer[0][(i * 12) + 7] =((-0.5f - y) * 8.0f);
                MT_VertexBuffer[0][(i * 12) + 8] =((-0.5f + x) * 8.0f);
                MT_VertexBuffer[0][(i * 12) + 9] =((-0.5f - y) * 8.0f);
                MT_VertexBuffer[0][(i * 12) +10] =((-0.5f + x) * 8.0f);
                MT_VertexBuffer[0][(i * 12) +11] = ((0.5f - y) * 8.0f);
                i++;
            }
        }
    }

   for (N = 0; N < 4; N++) {
       int z = 0;
       for (int y = 0; y < 15; y++) {
   
           for (int x = 0 + 16 * N; x < 16 + 16 * N; x++) {
   
               EditTile(z);
               z++;
           }
       }
   }

    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glBufferData(GL_ARRAY_BUFFER, 2880 * 4 * 4, MT_UVBuffer[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, 2880 * 4 * 4, MT_VertexBuffer[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, palette_buffer);
}

void Renderer::SetGUIScreen(TileScreen* guiscreen){
    GUIScreen = guiscreen;

    int z = 0;
    for (int y = 0; y < 15; y++) {

        for (int x = 0; x < 16; x++) {

            UpdateGUITile(z);
            z++;
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER, fuv_buffer);
    glBufferData(GL_ARRAY_BUFFER, 2880 * 4 * 4, GUI_UVBuffer, GL_STATIC_DRAW);
}

void Renderer::SetTileDigits(int score, unsigned char posR2L, unsigned char blankdigit) {
    unsigned short smallpos = (((posR2L - 32) & 31) + (posR2L / 64) * 32) / 2;
    while (score > 0) {
        int digit = score % 10;
        score /= 10;
        GUIScreen->tiles[posR2L] = digit;

        UpdateGUITile(smallpos);
        posR2L--;
        smallpos = (((posR2L - 32) & 31) + (posR2L / 64) * 32) / 2;
    }
    GUIScreen->tiles[posR2L] = blankdigit;
    UpdateGUITile(smallpos);
}

unsigned char Renderer::PlayAnimation(Entity* entity, Animation* animation, unsigned char endframe, unsigned char beginframe) {
   //if (entity->beginframe != beginframe) {
   //    entity->starttime = 0;
   //    entity->beginframe = beginframe;
   //    entity->frame = entity->beginframe;
   //    SetSpritetoEntity(entity, animation->sprites[entity->frame]); 
   //    SetAttributetoEntity(entity, animation->attribs[entity->frame++]);
   //    return 0;
   //}
    if (entity->frame < beginframe || entity->frame > endframe) {
        entity->frame = beginframe;
    }
    if (entity->starttime / animation->framerate) {

        entity->frame++;
        entity->starttime = 0;

        if (entity->frame > endframe) {
            entity->frame = beginframe;
            return 1;
        }
    }
    SetSpritetoEntity(entity, animation->sprites[entity->frame]);
    SetAttributetoEntity(entity, animation->attribs[entity->frame]);
    entity->starttime++;
    return 0;
}

//void Renderer::ProcessTileQueue() {
//    while (it != TileQueue.end()) {
//        EditTile(*it);
//        TileQueue.remove(*it);
//        it = TileQueue.begin();
//    }
//}

void Renderer::RenderScene(Scene* scene) {
   lo_CamX = scene->GetCamera()->X & 511;
   lo_CamY = scene->GetCamera()->Y & 511;
   overwrite_pos.y = (lo_CamY + scene->GetCamera()->scrolldir.y * 256); // 272 MAGIC NUMBER ALERT!
   overwrite_pos.x = (lo_CamX + scene->GetCamera()->scrolldir.x * 256);

   N = ((overwrite_pos.x >> 8) & 1);

   overwrite_pos.x *= 0.0625f;
   overwrite_pos.x &= 0xf;
 
   overwrite_pos.y *= 0.0625f;
   overwrite_pos.y &= 0xf;

 unsigned char split = (N & 2 | (lo_CamY / 256));
 scene->renderpos = ((scene->GetCamera()->X + scene->GetCamera()->scrolldir.x * 256) >> 8) + ((((scene->GetCamera()->Y + split * 256) >> 8) * 16) / 32) * 32;
 //printf("%d\n", split);
 
 if (split) {
     for (int x = overwrite_pos.x; x < overwrite_pos.y * 16; x += 16) {
         unsigned short bigpos = (x * 2 - (x & 15)) * 2;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         bigpos += 31;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         MainScreen[N]->attributes[x] = scene->TileScreens[scene->renderpos]->attributes[x];
         EditTile(x);
     }
 
     N += 2 - ((2 * (N & 2)));
 
     for (int x = overwrite_pos.x + overwrite_pos.y * 16; x < 240; x += 16) {
         unsigned short bigpos = (x * 2 - (x & 15)) * 2;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + (16 - 32 * split)]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + (16 - 32 * split)]->tiles[bigpos];
         bigpos += 31;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + (16 - 32 * split)]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + (16 - 32 * split)]->tiles[bigpos];
         MainScreen[N]->attributes[x] = scene->TileScreens[scene->renderpos + (16 - 32 * split)]->attributes[x];
         EditTile(x);
     }
 }
 else {
     for (int x = overwrite_pos.x + overwrite_pos.y * 16; x < 240; x += 16) {
         unsigned short bigpos = (x * 2 - (x & 15)) * 2;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         bigpos += 31;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         MainScreen[N]->attributes[x] = scene->TileScreens[scene->renderpos]->attributes[x];
         EditTile(x);
 
     }
 
     N += 2 - ((2 * (N & 2)));
 
 
     for (int x = overwrite_pos.x; x < overwrite_pos.y * 16; x += 16) {
         unsigned short bigpos = (x * 2 - (x & 15)) * 2;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + (16 - 32 * split)]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + (16 - 32 * split)]->tiles[bigpos];
         bigpos += 31;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + (16 - 32 * split)]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + (16 - 32 * split)]->tiles[bigpos];
         MainScreen[N]->attributes[x] = scene->TileScreens[scene->renderpos + (16 - 32 * split)]->attributes[x];
         EditTile(x);
 
     }
 }
 
 overwrite_pos.y = (lo_CamY + scene->GetCamera()->scrolldir.y * 256);
 
 N = ((overwrite_pos.y >> 8) * 2 & 3);
 
 overwrite_pos.y *= 0.0625f;
 overwrite_pos.y &= 0xf;
 
 split = (N & 1 | (lo_CamX / 256));
 scene->renderpos = (((scene->GetCamera()->X + split * 256) >> 8) / 2) * 2 + (((scene->GetCamera()->Y + scene->GetCamera()->scrolldir.y * 256) >> 8) * 16);
    
 if (split) {
     for (int x = overwrite_pos.y * 16; x < overwrite_pos.x + overwrite_pos.y * 16; x++) {
         unsigned short bigpos = (x * 2 - (x & 15)) * 2;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         bigpos += 31;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         MainScreen[N]->attributes[x] = scene->TileScreens[scene->renderpos]->attributes[x];
         EditTile(x);
     }
 
     N += 1 - ((2 * (N & 1)));
     //TODO:  overwrite_pos.x + overwrite_pos.y * 16; x < (16 - overwrite_pos.x) + overwrite_pos.x + overwrite_pos.y * 16
     // See if can be simplified
     for (int x = overwrite_pos.x + overwrite_pos.y * 16; x < (16 - overwrite_pos.x) + overwrite_pos.x + overwrite_pos.y * 16; x++) {
         unsigned short bigpos = (x * 2 - (x & 15)) * 2;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + 1 - split * 2]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + 1 - split * 2]->tiles[bigpos];
         bigpos += 31;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + 1 - split * 2]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + 1 - split * 2]->tiles[bigpos];
         MainScreen[N]->attributes[x] = scene->TileScreens[scene->renderpos + 1 - split * 2]->attributes[x];
         EditTile(x);
     }
 }
 else {
     for (int x = overwrite_pos.x + overwrite_pos.y * 16; x < (16 - overwrite_pos.x) + overwrite_pos.x + overwrite_pos.y * 16; x++) {
         unsigned short bigpos = (x * 2 - (x & 15)) * 2;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         bigpos += 31;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos]->tiles[bigpos];
         MainScreen[N]->attributes[x] = scene->TileScreens[scene->renderpos]->attributes[x];
         EditTile(x);
     }
 
     N += 1 - ((2 * (N & 1)));
     // + ((lo_CamX & 15) > 0) fixes "loose tile bug"
     for (int x = overwrite_pos.y * 16; x < overwrite_pos.x + (overwrite_pos.y + ((lo_CamX & 15) > 0)) * 16; x++) {
         unsigned short bigpos = (x * 2 - (x & 15)) * 2;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + 1 - split * 2]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + 1 - split * 2]->tiles[bigpos];
         bigpos += 31;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + 1 - split * 2]->tiles[bigpos];
         bigpos += 1;
         MainScreen[N]->tiles[bigpos] = scene->TileScreens[scene->renderpos + 1 - split * 2]->tiles[bigpos];
         MainScreen[N]->attributes[x] = scene->TileScreens[scene->renderpos + 1 - split * 2]->attributes[x];
         EditTile(x);
     }
 }

    unsigned short MainScreenPos_X = (lo_CamX / 256) * 512;
    unsigned short MainScreenPos_Y = (lo_CamY / 256) * 480;

    RenderMainScreens(scene, 0, Vector2{ MainScreenPos_X, MainScreenPos_Y });
    RenderMainScreens(scene, 1, Vector2{ 256,MainScreenPos_Y });
    RenderMainScreens(scene, 2, Vector2{ MainScreenPos_X,240 });
    RenderMainScreens(scene, 3, Vector2{ 256,240 });

    for (Entity* it : scene->entities) {
        if (((it->position.y) & 0x1ff) > 479) {
            it->position.y += -32 + scene->GetCamera()->scrolldir.y * 64;
        }
        lo_EntX = it->position.x & 511;
        lo_EntY = it->position.y & 511;

        glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1),glm::vec3(

            (lo_EntX - (((lo_EntX - lo_CamX)) / 256) * 512) - 128.001f,
           -(lo_EntY - (((lo_EntY - (lo_CamY + 128))) / 256) * 480) + 119.001f, //TODO: Search for better approach (lo_CamY + 208)
            0.0f));//Maybe change 119 to 120 for collision

        glm::mat4 MVP = scene->GetCamera()->GetProMat() * scene->GetCamera()->GetCamMat() * TranslationMatrix;

        GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        if (it->vertex_buffer) {
            RenderEntity(it);
        }
    }

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);
    glUniform1i(glGetUniformLocation(shaderProgram, "myTextureSampler"), 0);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_1D, bg_PaletteSampler);
    glUniform1i(glGetUniformLocation(shaderProgram, "myPaletteSampler"), 1);

    if (GUIScreen) {
        RenderGUIScreen(scene);
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


    position += 3;
    glDeleteTextures(1, &position);

    position += 7;

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
    entity->texture_buffer = position + 3;
    entity->vertex_buffer = position + 10;
}

void Renderer::SetAttributetoEntity(Entity* entity, GLuint attribute) {
    entity->uv_buffer = (attribute & 3) + 2;
}

void Renderer::AddtoTileMap(Tile tile, char position) {
    //TileMap.resize(512/*TileMap.size() + 16 * 16*/);
    int overwrite_pos = (position * 8); //change overwrite_pos // + (y * width)
    for (int y = 0; y < 8; y++) {
        overwrite_pos = (position * 8) + y; //change overwrite_pos // + (y * width)
        for (int x = 0 + y; x < 64; x += 8) {
            TileMap[overwrite_pos] = tile.pixels[x];
            overwrite_pos += (TileMap.size() / 64) * 8;
        }
    }

    glBindTexture(GL_TEXTURE_2D, tilemap_texture_buffer);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, TileMap.size() / 8, 8, GL_RED, GL_UNSIGNED_BYTE, TileMap.data());
}
void Renderer::RenderGUIScreen(Scene* scene) {

    glm::mat4 fMVP = glm::scale(glm::mat4(1), glm::vec3(0.0078125f, 0.0083333f,1.0f)) * glm::translate(glm::mat4(1), glm::vec3(-124.001f, 116.001f, 0.0f));

    GLuint fMatrixID = glGetUniformLocation(shaderProgram, "MVP");
    glUniformMatrix4fv(fMatrixID, 1, GL_FALSE, &fMVP[0][0]);

    GLuint fvertexPositionID = glGetAttribLocation(shaderProgram, "vertexPosition");
    glEnableVertexAttribArray(fvertexPositionID);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);

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
    glBufferData(GL_ARRAY_BUFFER, 2880 * 4 * 4, GUI_UVBuffer, GL_STATIC_DRAW);
    glVertexAttribPointer(
        fuvPositionID,       // attribute 0. No particular reason for 0, but must match the layout in the shader.
        2,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );
    glDrawArrays(GL_TRIANGLES, 0, 1440 * 4); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(fvertexPositionID);
    glDisableVertexAttribArray(fuvPositionID);
}


void Renderer::RenderMainScreens(Scene* scene, unsigned char num, Vector2 pos) {
    glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1), glm::vec3(pos.x -124.001f,-pos.y + 116.001f, 0.0f));

    glm::mat4 MVP = scene->GetCamera()->GetProMat() * scene->GetCamera()->GetCamMat() * TranslationMatrix;

    GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

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
    glBufferData(GL_ARRAY_BUFFER, 2880 * 4 * 4, MT_UVBuffer[num], GL_STATIC_DRAW);
    glVertexAttribPointer(
        uvPositionID,       // attribute 0. No particular reason for 0, but must match the layout in the shader.
        2,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );
    glDrawArrays(GL_TRIANGLES, 0, 1440 * 4); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(vertexPositionID);
    glDisableVertexAttribArray(uvPositionID);
}

void Renderer::RenderEntity(Entity* entity) {

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, entity->texture_buffer);
    glUniform1i(glGetUniformLocation(shaderProgram, "myTextureSampler"), 0);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_1D, bg_PaletteSampler);
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
    glDrawArrays(GL_TRIANGLES, 0, 6); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(vertexPositionID);
    glDisableVertexAttribArray(uvPositionID);
}
