#pragma once
#include "Singleton.h"
#include "SDL.h"
#include <Texture.h>
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

public:


	/*****************************************************************************/
private:
	
	std::vector<Music*> musics;
	std::vector<Sound*> sounds;

	// Private constructor to avoid more than one instance
	AudioManager();
	~AudioManager();

	void AddAudio(std::string, int);

	/*****************************************************************************/
public:

};

enum AudioTypes : int {		//Unscoped enum
	none = 0,
	music = 1,
	sound = 2
};