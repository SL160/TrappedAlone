#ifndef SCREEN_H
#define SCREEN_H

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <string>
#include <iostream>

class Screen
{
public:
	Screen(int width, int height, const std::string& title);

	void Update();

	bool Exited();

	virtual ~Screen();

protected:

private:
	Screen(const Screen& other) = delete;
	Screen& operator=( const Screen& other ) = delete;

	SDL_Window* m_Screen;
	SDL_GLContext m_glContext;

	bool m_exited;

};

#endif // SCREEN_H
