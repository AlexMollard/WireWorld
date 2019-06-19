#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <random>
#include <time.h>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	srand(time(0));

	_Font = new aie::Font("./font/consolas.ttf", 32);

	_2dRenderer = new aie::Renderer2D();

	_GridManager = new GridManager(25, getWindowWidth() ,getWindowHeight());

	setBackgroundColour(0.10f, 0.108f, 0.178f);

	return true;
}

void Application2D::shutdown() 
{
	delete _2dRenderer;
	delete _GridManager;
}

void Application2D::update(float deltaTime) 
{
	// input example
	aie::Input* input = aie::Input::getInstance();

	// Update GridManager
	_GridManager->Update(input, deltaTime, getWindowWidth(), getWindowHeight());

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw()
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	_2dRenderer->begin();
	
	// Draw GridManager
	_GridManager->Draw(_2dRenderer);

	//Draw FPS
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	_2dRenderer->setRenderColour(0.0f,1.0f,0.0f);
	_2dRenderer->drawText(_Font, fps, getWindowWidth() * 0.005, getWindowHeight() * 0.95);

	// done drawing sprites
	_2dRenderer->end();
}