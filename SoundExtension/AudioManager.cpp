#include "AudioManager.h"

//								Constructors
/*****************************************************************************/
#pragma region Constructors

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
#pragma endregion

//								Main functions
/*****************************************************************************/
#pragma region Main functions

bool AudioManager::AddAudio(std::string path, int type)
{
    bool success = true;
    if (type == AudioTypes::music) {
        //Load music
        Music* music = new Music();
        if (music == NULL) {
            printf("\nNot able to load that audio source.\n");
            success = false;
        }
        music = music->LoadFromFile(path);
        if (music == NULL)
        {
            printf("\nMusic is null, not added to the vector.\n");
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
            printf("\nNot able to load that audio source.\n");
            success = false;
        }
        sound = sound->LoadFromFile(path);
        if (sound == NULL)
        {
            printf("\nSound is null, not added to the vector.\n");
            success = false;
        }
        else
        {
            sounds.push_back(sound);
        }
    }
    return success;
}
#pragma endregion

//								Handle audios
/*****************************************************************************/
#pragma region Handle audios

void AudioManager::PlayAudio(std::string path)
{
    bool foundMusic = false;
    bool foundSound = false;
    for (int i = 0; i < musics.size(); i++) {
        if (musics[i]->GetPath() == path) {
            //If found, play the music
            musics[i]->Play();
            foundMusic = true;
        }
    }
    if (!foundMusic) {
        for (int i = 0; i < sounds.size(); i++) {
            if (sounds[i]->GetPath() == path) {
                //If found, play the sound
                sounds[i]->Play();
                foundSound = true;
            }
        }
    }
    if (!foundMusic && !foundSound) printf("\nERROR. Invalid path.\n");
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
        printf("\nERROR. Invalid path.\n");
    }
}

void AudioManager::StopMusic(std::string path)
{
    bool foundMusic = false;
    for (int i = 0; i < musics.size(); i++) {
        if (musics[i]->GetPath() == path) {
            //If found, stop the music
            musics[i]->Stop();
            foundMusic = true;
        }
    }
    if (!foundMusic) {
        printf("\nERROR. Invalid path.\n");
    }
}
#pragma endregion

/*****************************************************************************/
