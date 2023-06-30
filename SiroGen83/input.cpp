#include "input.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

Input* Input::_instance = 0;

void Input::Init(GLFWwindow* window)
{
	_window = window;
	GetMousePos();

}

Input::Input()
{
	_window = nullptr;
	mousepressed[7] = { 0 };
	mousereleased[7] = { 0 };
}

Input::~Input()
{
	//delete _instance;
}

bool Input::KeyPressed(KeyCode key)
{
	int keycode = (int)key;
	if (!glfwGetKey(_window, keycode))
	{
		keypressed[key] = false;
	}
	if (glfwGetKey(_window, keycode) && !keypressed[key])
	{
		keypressed[key] = true;
		return true;
	}
	return false;
}

bool Input::KeyReleased(KeyCode key)
{
	if (glfwGetKey(_window, (int)key))
	{
		keyreleased[key] = true;
	}
	if (!glfwGetKey(_window, (int)key) && keyreleased[key])
	{
		keyreleased[key] = false;
		return true;
	}
	return false;
}

bool Input::KeyDown(KeyCode key)
{
	return glfwGetKey(_window, (int)key);
}

bool Input::MousePressed(MouseButton button)
{
	if (glfwGetMouseButton(_window, (int)button) == GLFW_RELEASE)
	{
		mousepressed[(int)button] = 0;
	}
	if (glfwGetMouseButton(_window, (int)button) == GLFW_PRESS && !mousepressed[(int)button])
	{
		mousepressed[(int)button] = 1;
		return true;
	}
	return false;
}

bool Input::MouseReleased(MouseButton button)
{
	if (glfwGetMouseButton(_window, (int)button))
	{
		mousereleased[(int)button] = 1;
	}
	if (glfwGetMouseButton(_window, (int)button) == GLFW_RELEASE && mousereleased[(int)button])
	{
		mousereleased[(int)button] = 0;
		return true;
	}
	return false;
}

bool Input::MouseDown(MouseButton button)
{
	return glfwGetMouseButton(_window, (int)button);
}

//bool Input::MouseOver(Entity* collider)
//{
//	std::cout << mousecollider->transform->position->x << std::endl;
//	if (mousecollider->GetComponent<Collider>()->isColliding(collider))
//	{
//		return true;
//	}
//	return false;
//}

void Input::GetMousePos()
{
	glfwGetCursorPos(_window, &mousex, &mousey);
}