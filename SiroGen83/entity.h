#ifndef ENTITY_H_
#define ENTITY_H_
#include <SiroGen83/vector2.h>
#include <SiroGen83/input.h>

class Scene;

class Entity {
public:
	Entity();

	Vector2 position{0,0};

	virtual void BeginPlay();

	virtual void update();

	Input* GetInput() { return _instance; };

	void SetScene(Scene* scene) { _currentscene = scene; };

	template <typename T>
	T* GetScene() { return (T*)_currentscene; };

	unsigned char frame = 0;
	unsigned char flag = 0;

	friend class Renderer;

private:
	float starttime = 0.0f;

	unsigned short texture_buffer;

	unsigned short palette_buffer = 1;

	unsigned short vertex_buffer;

	unsigned short uv_buffer = 5;

	Scene* _currentscene = nullptr;

	Input* _instance = _instance->GetInstance();
};

#endif
