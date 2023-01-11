#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() {
    projectionMatrix = glm::ortho(
        0.0f,
        1920.0f,
        -1080.0f,
        0.0f,
        0.1f,
        1000.0f
    );
}

void Camera::update(unsigned char mode) {
    if (((Y + scrolldir.y * 256) & 0xff) > 239) {
        Y += -16 + scrolldir.y * 32;
    }

    offset = glm::vec3((1920.0f + 1024.0f * (mode & 1)) / 2, (-1080.0f - 480.0f * (mode & 2)) / 2, 0);

    cameraMatrix = glm::lookAt(
        glm::vec3(X & 0x1FF,-((Y & 0x1ff) - 16 * (Y >> 8 & 1)), 1.0f) - offset, //position
        glm::vec3(X & 0x1FF,-((Y & 0x1ff) - 16 * (Y >> 8 & 1)), 1.0f) - offset + glm::vec3(0.0f, 0.0f, -1.0f), //direction
        glm::vec3(0.0f, 1.0f, 0.0f)
    );
}
