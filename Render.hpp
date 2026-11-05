#include <sdl2/SDL.h>

class Render
{
public:
    SDL_Window *window;
    SDL_Renderer *renderer;

    int Init(const char *Name, float x, float y)
    {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
        {
            meh.ShowFatalError("Initialization Error", "Failed to initialize SDL");
            return 0;
        }

        SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");

        window = SDL_CreateWindow(
            Name,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            x,
            y,
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

        if (window == nullptr)
        {
            meh.ShowFatalError("Initialization Error", "Failed to create SDL window");
            SDL_Quit();
            return 1;
        }

        renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

        if (renderer == nullptr)
        {
            meh.ShowFatalError("Initialization Error", "Failed to create SDL renderer");
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 2;
        }
        return 3;
    }

    void Shutdown()
    {
        if (renderer)
        {
            SDL_DestroyRenderer(renderer);
            renderer = nullptr;
        }
        if (window)
        {
            SDL_DestroyWindow(window);
            window = nullptr;
        }
        SDL_Quit();
    }
};
