#include "MusicBox.h"

MusicBox::MusicBox(){

    currentSampleInstance = NULL;
    currentSongName = "";
}

MusicBox::~MusicBox(){

#ifndef NO_MUSIC
    al_stop_sample_instance(currentSampleInstance);
#endif

    removeAllSongs();
}

void MusicBox::playSong(std::string songName){

#ifndef NO_MUSIC
    //Create iterator for testing if the element exists.
    std::map<std::string , Song*>::iterator iter = songs.begin();

    iter = songs.find(songName);

    if(iter == songs.end()){

        //Element not found.
        return;    
    }

    if(currentSongName == songName){

        //Song is already playing.
        return;
    }

    else{

        if(currentSampleInstance != NULL){
            al_stop_sample_instance(currentSampleInstance);
        }

        currentSampleInstance = iter->second->sampleInstance;
        al_play_sample_instance(currentSampleInstance);
        currentSongName = songName;
    }
#endif
}

void MusicBox::stopCurrentSong(){

    al_stop_sample_instance(currentSampleInstance);
}

void MusicBox::loadSong(std::string songName , std::string songFilePath){

    const char * filePath = songFilePath.c_str();

    Song *song = new Song();
    song->sample = al_load_sample(filePath);
    song->sampleInstance = al_create_sample_instance(song->sample);
    al_set_sample_instance_playmode(song->sampleInstance , ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(song->sampleInstance , al_get_default_mixer());

    songs.insert(std::pair<std::string , Song*>(songName , song));
}

void MusicBox::loadAllSongs(){

#ifndef NO_MUSIC
    al_reserve_samples(10);

    loadSong("Moonlight Hall" , "Music/Moonlight Hall.ogg");
    loadSong("Enchanted Valley" , "Music/Enchanted Valley.ogg");
    loadSong("Dreamy Flashback" , "Music/Dreamy Flashback.ogg");
    loadSong("Alchemists Tower" , "Music/Alchemists Tower.ogg");
    loadSong("Frost Waltz" , "Music/Frost Waltz.ogg");
    loadSong("Metaphysik" , "Music/Metaphysik.ogg");
    loadSong("Mistake The Getaway" , "Music/Mistake The Getaway.ogg");
    loadSong("Split In Synapse" , "Music/Split In Synapse.ogg");
    loadSong("Vulcan" , "Music/Vulcan.ogg");
    loadSong("Motivator" , "Music/Motivator.ogg");
    loadSong("Arcadia" , "Music/Arcadia.ogg");
#endif
}

void MusicBox::removeAllSongs(){

    std::map<std::string , Song*>::iterator iter = songs.begin();

    while(iter != songs.end()){

        al_destroy_sample(iter->second->sample);
        al_destroy_sample_instance(iter->second->sampleInstance);

        iter->second = NULL;
        songs.erase(iter);
        iter = songs.begin();
    }
}