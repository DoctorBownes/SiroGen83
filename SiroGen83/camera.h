#pragma once
#include <glm/glm.hpp>

struct SCector2 {
	signed char x;
	signed char y;
};

class Camera {
public:
	Camera();

	void SetZoom(float amount);

	void update(unsigned char mode = 0);

	glm::mat4 GetCamMat() { return cameraMatrix; };

	glm::mat4 GetProMat() { return projectionMatrix; };

	unsigned short X = 0;

	unsigned short Y = 0;

	SCector2 scrolldir{0,0};

	glm::vec3 offset;

private:
	glm::mat4 cameraMatrix;
	glm::mat4 projectionMatrix;

};
