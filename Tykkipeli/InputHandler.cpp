#include "InputHandler.h"


InputHandler::InputHandler(void)
{
	quit = false;
	this->mouseClicked = false;
}


InputHandler::~InputHandler(void)
{
}

void InputHandler::handleInput() {
	SDL_Event event;
	this->mouseClicked = false;

	if(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				this->quit = true;
			}
			if (event.type == SDL_KEYDOWN)
			{
				SDLKey keyPressed = event.key.keysym.sym;
				switch (keyPressed)
				{
					case SDLK_ESCAPE:
					this->quit = true;
					break;
				}
			}
			if(event.type == SDL_MOUSEBUTTONDOWN) {
				this->mouseClicked = true;
				this->mouseX = event.button.x;
				this->mouseY = event.button.y;
			}
		}

}

bool InputHandler::isMouseClicked() {
	return this->mouseClicked;
}

bool InputHandler::isQuit() {
	return this->quit;
}

int InputHandler::getMouseX() {
	return this->mouseX;
}

int InputHandler::getMouseY() {
	return this->mouseY;
}