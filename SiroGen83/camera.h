#pragma once
#include <glm/glm.hpp>

class Camera {
public:
	Camera();

	void SetZoom(float amount);

	void update();

	glm::mat4 GetCamMat() { return cameraMatrix; };

	glm::mat4 GetProMat() { return projectionMatrix; };

	float X = 0.0f;
	float Y = 0.0f;

private:
	glm::mat4 cameraMatrix;
	glm::mat4 projectionMatrix;

	glm::vec3 offset;
};
