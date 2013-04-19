#include "SDL.h"

#pragma once
class InputHandler
{
public:
	InputHandler(void);
	~InputHandler(void);
	void handleInput();
	bool isMouseClicked();
	bool isQuit();
	int getMouseX();
	int getMouseY();

private:
	bool quit;
	bool mouseClicked;
	int mouseX, mouseY;
};

