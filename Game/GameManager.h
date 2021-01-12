#pragma once
/*
 * Game Manager class
 */
class GameManager {

private:

	int leftPlayerPoints;
	int rightPlayerPoints;

public:

	//Constructors
	GameManager();
	
	void AddPointLeft();
	void AddPointRight();
};