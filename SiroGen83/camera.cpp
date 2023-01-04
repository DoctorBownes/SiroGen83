#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() {
    SetZoom(1.0f);
}

void Camera::SetZoom(float amount) {
    projectionMatrix = glm::ortho(
        0.0f,
        1920.0f / amount,
        -1080.0f / amount,
        0.0f,
        0.1f,
        1000.0f
    );

    offset = glm::vec3((1920.0f / amount) / 2, (-1080.0f / amount) / 2, 0);

}

void Camera::update() {
    if ((Y + (((scrolldir.y >> 8) & 1) * -256) + 256 & 0xff) > 239) {
        Y += 16 - (((scrolldir.y >> 8) & 1) * 32);
    }

    cameraMatrix = glm::lookAt(
        glm::vec3(X & 0x1FF,-((Y & 0x1ff) - 16 * (Y >> 8 & 1)), 1.0f) - offset, //position
        glm::vec3(X & 0x1FF,-((Y & 0x1ff) - 16 * (Y >> 8 & 1)), 1.0f) - offset + glm::vec3(0.0f, 0.0f, -1.0f), //direction
        glm::vec3(0.0f, 1.0f, 0.0f)
    );
}
