#include "Screen.h"
#include <GL/glew.h>
#include <iostream>

Screen::Screen( int width, int height, const std::string& title )
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_Screen = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_Screen);

	GLenum status = glewInit();

	if(status != GLEW_OK)
	{
		std::cerr << "Glew Did Not Load!" << std::endl;
	}

	m_exited = false;
}

Screen::~Screen()
{
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_Screen);
	SDL_Quit();
}

bool Screen::Exited()
{
	return m_exited;
}

void Screen::Update()
{
	SDL_GL_SwapWindow(m_Screen);


}
