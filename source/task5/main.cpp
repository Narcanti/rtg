


#include <iostream>
#include <stdexcept>

#include <GL/platform/Window.h>

#include "Renderer.h"
#include "InputHandler.h"


int main(int argc, char* argv[])
{
	try
	{
		GL::platform::Window window("Assignment 5 — Special Effect", 800, 600, 24, 8, false, 3, 3);
		Renderer renderer(window);
		InputHandler input_handler;

		window.attach(static_cast<GL::platform::KeyboardInputHandler*>(&input_handler));
		window.attach(static_cast<GL::platform::MouseInputHandler*>(&input_handler));

		GL::platform::run(renderer);
	}
	catch (std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
		return -1;
	}
	catch (...)
	{
		std::cout << "unknown exception" << std::endl;
		return -128;
	}

	return 0;
}
