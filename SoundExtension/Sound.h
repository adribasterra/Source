#pragma once

#include <SDL_mixer.h>
#include <string>

/**
 * Sound Base class
 */
class Sound
{

public:

	Mix_Chunk* gSound;

	Sound();
	~Sound();

	//Getters
	std::string GetPath();

	Sound* LoadFromFile(std::string path);

	//Handle audio
	void Play();

	/*****************************************************************************/
private:

	std::string path;

	/*****************************************************************************/
};

