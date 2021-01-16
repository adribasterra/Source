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

void AudioManager::AddAudio(std::string path, int type)
{
    if (type == AudioTypes::music) {
        //Load music
        Music* music = new Music();
        music = music->LoadFromFile(path);
        musics.push_back(music);
    }
    else if(type == AudioTypes::sound) {
        //Load sound
        Sound* sound = new Sound();
        sound = sound->LoadFromFile(path);
        sounds.push_back(sound);
    }
}

/*****************************************************************************/
