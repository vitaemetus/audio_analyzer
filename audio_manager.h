#pragma once
#include <cstdlib>
#include <string>
#include "AudioFile/AudioFile.h"
struct audio_manager {
    audio_manager(std::string filename): filename(filename){
        audioFile.load ("test.wav");
    }
    audio_manager(){audio_manager{"test.wav"}}
    void play(){
        system(("afplay " + filename).c_str());
    }
    private:
    std::string filename;
    AudioFile<double> audioFile;
};