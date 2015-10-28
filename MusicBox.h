#pragma once
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <string>
#include <map>

#define NO_MUSIC

class MusicBox{

private:

    struct Song{

        ALLEGRO_SAMPLE *sample;
        ALLEGRO_SAMPLE_INSTANCE *sampleInstance;    
    };

    ALLEGRO_SAMPLE_INSTANCE *currentSampleInstance;
    std::string currentSongName;

    //Collection of songs.
    std::map<std::string , Song*> songs;

    void loadSong(std::string songName , std::string songFilePath);

public:

    MusicBox();
    ~MusicBox();
    void playSong(std::string songName);
    void stopCurrentSong();
    void loadAllSongs();
    void removeAllSongs();
};