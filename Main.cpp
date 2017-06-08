#include <iostream>
#include <string>
#include "Screen.h"
#include "Sound.h"

bool SDL() {
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "SDL_mixer could not load! SDL_mixer error: " << Mix_GetError() << endl;
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	Screen screen(800, 600, "Hello World");

	SDL();
	Mix_Music* pBackgroundTrack = NULL;

	pBackgroundTrack = backgroundMusic("Music.wav");
	Mix_PlayMusic(pBackgroundTrack, -1);

	while (!screen.Exited())
	{
		

		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		SDL_Event pressed;

		while (SDL_PollEvent(&pressed))
		{
			switch (pressed.type)
			{
			case SDL_KEYDOWN:
				switch (pressed.key.keysym.sym)
				{
				case SDLK_w:
					std::cout << "W pressed" << std::endl;
					break;
				case SDLK_s:
					std::cout << "S pressed" << std::endl;
					break;
				case SDLK_a:
					std::cout << "A pressed" << std::endl;
					break;
				case SDLK_d:
					std::cout << "D pressed" << std::endl;
					break;
				}
				break;
			}
		}

		screen.Update();

	}

	Mix_HaltMusic();
	Mix_FreeMusic(pBackgroundTrack);
	pBackgroundTrack = NULL;

	return 0;
}