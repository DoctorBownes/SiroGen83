#ifndef CAMERA_H_
#define CAMERA_H_
#include <glm/glm.hpp>

struct Bector2 {
	bool x;
	bool y;
};

class Camera {
public:
	Camera();

	void update();

	glm::mat4 GetCamMat() { return cameraMatrix; };

	glm::mat4 GetProMat() { return projectionMatrix; };

	unsigned short X = 0;

	unsigned short Y = 0;

	Bector2 scrolldir{0,0};

	glm::vec3 offset;

private:
	glm::mat4 cameraMatrix;
	glm::mat4 projectionMatrix;

};

#endif
