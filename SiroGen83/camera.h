#pragma once
#include <glm/glm.hpp>

class Camera {
public:
	Camera();

	void SetZoom(float amount);

	void update();

	glm::mat4 GetCamMat() { return cameraMatrix; };

	glm::mat4 GetProMat() { return projectionMatrix; };

	unsigned char X = 0;
	unsigned char Y = 0;

private:
	glm::mat4 cameraMatrix;
	glm::mat4 projectionMatrix;

	glm::vec3 offset;
};
