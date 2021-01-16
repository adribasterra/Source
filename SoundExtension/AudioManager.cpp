#include "AudioManager.h"

//								Constructors
/*****************************************************************************/

AudioManager::AudioManager()
{
    musics = std::vector<Music*>();
    sounds = std::vector<Sound*>();
    musics.reserve(10);
    sounds.reserve(10);
}

AudioManager::~AudioManager(void)
{
    //Destroy musics
    for (int i = 0; i < musics.size(); i++) {
        delete(musics[i]);
    }
    musics.clear();

    //Destroy sounds
    for (int i = 0; i < sounds.size(); i++) {
        delete(sounds[i]);
    }
    sounds.clear();
}

//								Main functions
/*****************************************************************************/



/*****************************************************************************/
