#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "AudioFile/AudioFile.h"
struct audio_manager {
    audio_manager(std::string filename): filename(filename){
        audioFile.load (filename);
    }
    audio_manager(){audio_manager{"test.wav"};}
    void play(){
        system(("afplay " + filename).c_str());
    }
    void summ(){audioFile.printSummary();}
    void compress(int samps){
        if(samps<audioFile.getSampleRate()){
            audioFile.setNumSamplesPerChannel (samps);
        }
        else throw "Less samples than original";
    }
    private:
    std::string filename;
    AudioFile<double> audioFile;
};