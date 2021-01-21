#pragma once

#include <SDL_mixer.h>
#include <string>

/**
 * Music Base class
 */
class Music
{

public:

	Mix_Music* gMusic;

	//Constructors
	Music();
	~Music();

	//Getters
	std::string GetPath();

	Music* LoadFromFile(std::string);

	//Handle audio
	void Play();
	void Pause();
	void Stop();

	/*****************************************************************************/
private:

	std::string path;

	/*****************************************************************************/
};

