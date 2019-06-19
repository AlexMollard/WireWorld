#include "Cell.h"
#include <iostream>
#include "Input.h"
using namespace std;

Cell::Cell()
{
	// Initializing variables
	_Alive = true;
	_DeathRow = false;
	_ChangeType = 1;
	_R = 0.0f;
	_G = 0.0f;
	_B = 0.0f;
	_CellX = 0.0f;
	_CellY = 0.0f;
	_Survive = true;
	_Type = 1;
	_Timer = 0;
	_Wall = false;
	_ChangeLit = false;
	_Lit = false;
}

void Cell::Draw(aie::Renderer2D* renderer)
{
}

void Cell::Update(float DeltaTime, aie::Input* input)
{
	_Timer += DeltaTime * 10;

	MouseOver(input);

	if (_Survive)
		_Alive = true;
	else
		_Alive = false;

	SetType(_ChangeType);
	_Lit = GetChangeLit();

	// Set colour for each type of cell
	if (_Wall)
	{
		_R = 1.0f;
		_G = 1.0f;
		_B = 1.0f;
	}
	else if (_Alive && _Type == 1)	// Wire
	{
		_R = 0.3f;
		_G = 0.3f;
		_B = 0.3f;
	}
	else if (_Alive && _Type == 2)	// Power
	{
		_R = 0.7f;
		_G = 0.7f;
		_B = 0.2f;
	}
	else if (_Alive && _Type == 3)	// Trail
	{
		_R = 0.7f;
		_G = 0.2f;
		_B = 0.2f;
	}
	else if (_Alive && _Type == 4 && !_Lit)	// Light Dark
	{
		_R = 0.2f;
		_G = 0.2f;
		_B = 0.2f;
	}
	else if (_Alive && _Type == 4 && _Lit)	// Light Lit
	{
		_R = 0.7f;
		_G = 0.7f;
		_B = 0.7f;
	}
	
	// If the cell is dead make it black
	if (!_Alive && !_Wall)
	{
		_R = 0.0f;
		_G = 0.0f;
		_B = 0.0f;
	}
}

void Cell::MouseOver(aie::Input* input)
{
	// Save Cell
	if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
	{
		if (_Timer > 2)
		{
			if (input->getMouseX() >= _CellX - (_SizeX) && input->getMouseX() <= _CellX + (_SizeX) &&
				input->getMouseY() >= _CellY - (_SizeY) && input->getMouseY() <= _CellY + (_SizeY))
			{
				if (_Survive)
				{
					_ChangeType += 1;
					if (_ChangeType == 5)
						_ChangeType = 1;


				}
					if (input->isKeyDown(aie::INPUT_KEY_LEFT_SHIFT))
						_ChangeType = 4;
				_Survive = true;
			}

			_Timer = 0;
		}
	}

	// Kill Cell
	if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_RIGHT))
	{
		if (_Timer > 2)
		{
			if (input->getMouseX() >= _CellX - (_SizeX / 2) && input->getMouseX() <= _CellX + (_SizeX / 2) &&
				input->getMouseY() >= _CellY - (_SizeY / 2) && input->getMouseY() <= _CellY + (_SizeY / 2))
			{
				_Survive = false;
			}

			_Timer = 0;
		}
	}
}