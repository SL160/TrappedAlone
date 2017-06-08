#include "Sound.h"

Mix_Music* backgroundMusic(string path)
{
	Mix_Music* pBMusic = NULL;

	pBMusic = Mix_LoadMUS(path.c_str());

	if (NULL == pBMusic)
	{
		std::cout << "Failed to lose Music: " << path << "!SDL_Mixer Error: " << Mix_GetError() << endl;;
	}

	return pBMusic;
}

Mix_Chunk* soundBite(string path)
{
	Mix_Chunk* pSBite = NULL;

	pSBite = Mix_LoadWAV(path.c_str());

	if (NULL == pSBite)
	{
		std::cout << "Failed to lose Sound Bite: " << path << "!SDL_Chunk Error: " << Mix_GetError() << endl;;
	}

	return pSBite;
}