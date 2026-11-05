Fundamental 2D 

Small library for faster initialization of SDL2 projects.

Instructions:
	Include the library
	Initialize the SDL2 by F2D::Init(window_name, width, height);
	Add a loop, and add your logic
	Shutdown the SDL2 by F2D::Shutdown();

Extra:
	F2D.hpp also include SDL_Render and SDL_Window variables.
	Render: F2D::renderer
	Window: F2D::window

Example:

	#include <F2D.hpp>

	int main()
	{
		F2D::Init();
		while(true)
		{
			//Your logic, like SDL2 event poll
		}
		F2D::Shutdown();
	}
