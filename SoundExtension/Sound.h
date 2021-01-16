#pragma once
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
/*
 * Sound Base class
 */
class Sound
{
public:
	Mix_Chunk* gSound;

	Sound();
	~Sound();

	std::string GetPath();

	bool LoadFromFile(std::string path);

	void Play();

private:
	std::string path;
};

