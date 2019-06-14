#pragma once
#include <Renderer2D.h>
#include "Input.h"
class Cell
{
public:
	Cell();

	// Update Functions
	void Update(float DeltaTime, aie::Input* input);
	void Draw(aie::Renderer2D* renderer);
	void MouseOver(aie::Input* input);

	// Postition Functions
	void SetPos(float x, float y)	{ _CellX = x;  _CellY = y; };
	float GetX()					{ return _CellX; };
	float GetY()					{ return _CellY; };
	
	// Alive Functions
	bool GetAlive()					{ return _Alive; };
	void SetAlive(bool alive)		{ _Alive = alive; };

	// Survive Functions
	bool GetSurvive()				{ return _Survive; };
	void SetSurvive(bool Survive)	{ _Survive = Survive; };

	// DeathRow Functions
	bool GetDeathRow()				{ return _DeathRow; };
	void SetDeathRow(bool death)	{ _DeathRow = death; };

	// Wall Functions
	bool GetWall()					{ return _Wall; };
	void SetWall(bool Wall)			{ _Wall = Wall; };

	// Type Functions
	int GetType()					{ return _Type; };
	void SetType(char type)			{ _Type = type; };

	// SizeX Functions
	float GetSizeX()						{ return _SizeX; };
	float GetSizeY()						{ return _SizeY; };
	void SetSize(float sizeX, float sizeY)	{ _SizeX = sizeX; _SizeY = sizeY; };

	// Colour Functions
	float GetR()					{ return _R; };
	float GetG()					{ return _G; };
	float GetB()					{ return _B; };


private:
	// Next Generation Status
	bool _DeathRow;
	bool _Survive;
	bool _Alive;

	// Position Variables
	float _CellX;
	float _CellY;

	// Size Variables
	float _SizeX;
	float _SizeY;

	// Colour Variables 
	float _R;
	float _G;
	float _B;
	int _Type;	

	// Wall Variable
	bool _Wall;

	// Timer Variable
	float _Timer;
};

