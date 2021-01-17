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

AudioManager::~AudioManager()
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
        if (music == NULL) {
            printf("Not able to load that audio source.");
            return;
        }
        music = music->LoadFromFile(path);
        musics.push_back(music);
    }
    else if(type == AudioTypes::sound) {
        //Load sound
        Sound* sound = new Sound();
        if (sound == NULL) {
            printf("Not able to load that audio source.");
            return;
        }
        sound = sound->LoadFromFile(path);
        sounds.push_back(sound);
    }
}

void AudioManager::PlayAudio(std::string path)
{
    bool foundMusic = false;
    bool foundSound = false;
    for (int i = 0; i < musics.size(); i++) {
        if (musics[i]->GetPath() == path) {
            musics[i]->Play();
            foundMusic = true;
        }
    }
    if (!foundMusic) {
        for (int i = 0; i < sounds.size(); i++) {
            if (sounds[i]->GetPath() == path) {
                sounds[i]->Play();
                foundSound = true;
            }
        }
    }
    if (!foundMusic && !foundSound) printf("ERROR. Invalid path.");
}

void AudioManager::PauseMusic(std::string path)
{
    bool foundMusic = false;
    for (int i = 0; i < musics.size(); i++) {
        if (musics[i]->GetPath() == path) {
            musics[i]->Pause();
            foundMusic = true;
        }
    }
    if (!foundMusic) {
        printf("ERROR. Invalid path.");
    }
}

void AudioManager::StopMusic(std::string path)
{
    bool foundMusic = false;
    for (int i = 0; i < musics.size(); i++) {
        if (musics[i]->GetPath() == path) {
            musics[i]->Stop();
            foundMusic = true;
        }
    }
    if (!foundMusic) {
        printf("ERROR. Invalid path.");
    }
}

/*****************************************************************************/
