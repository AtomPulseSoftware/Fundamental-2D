# Fundamental 2D

Small library for faster initialization of SDL2 projects.

## Instructions

- Include the library.
- Initialize SDL2 with `F2D::Init(window_name, width, height);`.
- Add a loop and your logic.
- Shut down SDL2 with `F2D::Shutdown();`.

## Extra

`F2D.hpp` also includes the `SDL_Renderer` and `SDL_Window` variables:

- Renderer: `F2D::renderer`
- Window: `F2D::window`

## Example

```cpp
#include <F2D.hpp>

int main()
{
    F2D::Init();
    while (true)
    {
        // Your logic, like SDL2 event polling
    }
    F2D::Shutdown();
}
```
