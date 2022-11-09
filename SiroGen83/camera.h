#pragma once
#include <glm/glm.hpp>
#include <SiroGen83/vector2.h>

class Camera {
public:
	Camera();

	void SetZoom(float amount);

	void update();

	glm::mat4 GetCamMat() { return cameraMatrix; };

	glm::mat4 GetProMat() { return projectionMatrix; };

	Vector2 position;

private:
	glm::mat4 cameraMatrix;
	glm::mat4 projectionMatrix;

	glm::vec3 offset;
};
