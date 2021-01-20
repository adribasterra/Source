#include "AudioManager.h"

//								Constructors
/*****************************************************************************/

AudioManager::AudioManager()
{
    musics = std::vector<Music*>();
    sounds = std::vector<Sound*>();
    musics.reserve(10);
    sounds.reserve(10);

    //Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
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

bool AudioManager::AddAudio(std::string path, int type)
{
    bool success = true;
    if (type == AudioTypes::music) {
        //Load music
        Music* music = new Music();
        if (music == NULL) {
            printf("Not able to load that audio source.");
            success = false;
        }
        music = music->LoadFromFile(path);
        if (music == NULL)
        {
            printf("Music is null, not added to the vector");
            success = false;
        }
        else
        {
            musics.push_back(music);
        }
    }
    else if(type == AudioTypes::sound) {
        //Load sound
        Sound* sound = new Sound();
        if (sound == NULL) {
            printf("Not able to load that audio source.");
            success = false;
        }
        sound = sound->LoadFromFile(path);
        if (sound == NULL)
        {
            printf("Sound is null, not added to the vector");
            success = false;
        }
        else
        {
            sounds.push_back(sound);
        }
    }
    return success;
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
