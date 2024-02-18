#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() {
    projectionMatrix = glm::ortho(
        0.0f,
        256.0f,
        -240.0f,
        0.0f,
        0.1f,
        1000.0f
    );
}

void Camera::update() {
    if (((Y) & 0xff) > 239) {
        Y += -16 + scrolldir.y * 32;
    }

    offset = glm::vec3(256.0f / 2, -240.0f / 2, 0);

    cameraMatrix = glm::lookAt(
        glm::vec3(X & 0x1FF,-((Y & 0x1ff) - 16 * (Y >> 8 & 1)), 1.0f) - offset, //position
        glm::vec3(X & 0x1FF,-((Y & 0x1ff) - 16 * (Y >> 8 & 1)), 1.0f) - offset + glm::vec3(0.0f, 0.0f, -1.0f), //direction
        glm::vec3(0.0f, 1.0f, 0.0f)
    );
}

unsigned short Camera::MovCamHor(signed char speed) {
    scrolldir.x = ~speed >> 8;
    X += speed;
    return X;
}

unsigned short Camera::MovCamVer(signed char speed) {
    scrolldir.y = ~speed >> 8;
    Y += speed;
    return Y;
}
