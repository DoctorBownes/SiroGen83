#include "input.h"
#include <GLFW/glfw3.h>

Input* Input::_instance = 0;

void Input::Init(GLFWwindow* window)
{
	_window = window;
	GetMousePos();

}

Input::Input()
{
	_window = nullptr;
	keypressed[347] = { 0 };
	keyreleased[347] = { 0 };
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
		keypressed[keycode] = false;
	}
	if (glfwGetKey(_window, keycode) && !keypressed[keycode])
	{
		keypressed[keycode] = true;
		return true;
	}
	return false;
}

bool Input::KeyReleased(KeyCode key)
{
	if (glfwGetKey(_window, (int)key))
	{
		keyreleased[(int)key] = 1;
	}
	if (!glfwGetKey(_window, (int)key) && keyreleased[(int)key])
	{
		keyreleased[(int)key] = 0;
		return true;
	}
	return false;
}

bool Input::KeyDown(KeyCode key)
{
	if (glfwGetKey(_window, (int)key) == GLFW_PRESS)
	{
		return true;
	}
	return false;
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
	if (glfwGetMouseButton(_window, (int)button) == GLFW_PRESS)
	{
		return true;
	}
	return false;
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