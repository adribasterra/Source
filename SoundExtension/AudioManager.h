#pragma once

#include "Singleton.h"
#include "SDL.h"
#include <vector>
#include "Music.h"
#include "Sound.h"

/*
 * Audio Manager class
 */
class AudioManager : public Singleton<AudioManager>
{
	/*****************************************************************************/
	friend class Singleton<AudioManager>;
	/*****************************************************************************/

private:
	
	std::vector<Music*> musics;
	std::vector<Sound*> sounds;

	// Private constructor to avoid more than one instance
	AudioManager();
	~AudioManager();

	/*****************************************************************************/
public:

	bool AddAudio(std::string, int);

	void PlayAudio(std::string);
	void PauseMusic(std::string);
	void StopMusic(std::string);
};

/*****************************************************************************/

enum AudioTypes : int {		//Unscoped enum
	music = 0,
	sound = 1
};