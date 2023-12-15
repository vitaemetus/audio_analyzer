#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "AudioFile/AudioFile.h"
#include <vector>
#include <chrono>
#include <thread>
struct audio_manager {
    audio_manager(std::string filename): filename(filename){
        audioFile.load (filename);
        framesamp=audioFile.getSampleRate();
        if(framesamp!=audioFile.getSampleRate()) std::cout<<"wrong fps";
    }
    audio_manager(){audio_manager{"test.wav"};}
    void play(){
        start=std::chrono::system_clock::now();
        system(("afplay " + filename).c_str());

    }
    std::vector <float> get_samples(){

        current_sample+=framesamp;
        return std::vector <float> (audioFile.samples[0].begin()+(current_sample-framesamp), audioFile.samples[0].begin()+current_sample);
    }
    bool wait(){
        std::chrono::duration<double> diff = std::chrono::system_clock::now() - start;
        if(diff.count()+1>=lengthInSeconds) return 0;
        else if(diff.count()<current_sample/fps){
            int delay = (current_sample/fps-diff.count())*1e6;
            std::this_thread::sleep_for(std::chrono::microseconds(delay));
        }
        else {
            std::cout<<"late";
        }
        return 1;
    }
    void summ(){audioFile.printSummary();}

    private:
    std::string filename;
    AudioFile<double> audioFile;
    int framesamp;
    int fps=30;
    int current_sample=0;
    std::chrono::time_point<std::chrono::system_clock> start;
    double lengthInSeconds = audioFile.getLengthInSeconds();
};