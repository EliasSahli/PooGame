
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Poo.h"
#include "Dude.h"
#include "Goal.h"
#include "Meter.h"
#include "SoundEffect.h"
#include <random>
#include "FrameTimer.h"
#include "Vec2.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawGameOver( int x,int y );
	void DrawTitleScreen( int x,int y );
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	FrameTimer ft;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist;
	std::uniform_real_distribution<float> yDist;
	Dude dude;
	Goal goal;
	Meter meter;
	static constexpr int nPoo = 10;
	Poo poos[nPoo];
	bool isStarted = false;
	bool isGameOver = false;
	SoundEffect pickup = SoundEffect( { L"Sounds\\coin.wav" } );
	Sound title = Sound( L"Sounds\\title.wav" );
	SoundEffect fart = SoundEffect( 
		{ L"Sounds\\fart1.wav",L"Sounds\\fart2.wav" } );
	/********************************/
};