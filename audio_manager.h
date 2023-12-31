#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "AudioFile/AudioFile.h"
#include <vector>
#include <chrono>
#include <thread>
struct audio_manager {
    audio_manager(std::string file){
        filename=file;
        audioFile.load (filename);
        lengthInSeconds = audioFile.getLengthInSeconds();
        framesamp=audioFile.getSampleRate()/fps;
        if(framesamp!=audioFile.getSampleRate()/fps) std::cout<<"wrong fps";
    }
    void play(){
        start=std::chrono::system_clock::now();
        //std::cout<<'\n'<<filename<<2;
        system(("osascript -e \'tell app \"Terminal\" to do script \"afplay " + filename + "\" \'").c_str());
    }
    void set_fps(int frames){
        fps=frames;
    }
    void set_data_len(int l){
        if(l<framesamp) data_len=framesamp;
        else{
            std::cout<<"too many samples";
            data_len=framesamp;
        }
    }
    std::vector <float> get_samples(){

        current_sample+=framesamp;
        return std::vector <float> (audioFile.samples[0].begin()+(current_sample-data_len), audioFile.samples[0].begin()+current_sample);
    }
    bool wait(){
        std::chrono::duration<double> diff = std::chrono::system_clock::now() - start;
        //std::cout<<"\n"<<diff.count()<<' '<<lengthInSeconds;
        if(diff.count()+1>=lengthInSeconds) return 0;
        else if(diff.count()<current_sample/framesamp/fps/fps){
            return 1;
            int delay = (current_sample/framesamp/fps/fps-diff.count())*1e3;
            //std::cout<<"delay:"<<delay<<'\n';
            std::this_thread::sleep_for(std::chrono::milliseconds(delay)); 
        }
        else {
            //std::cout<<"late";
        }
        return 1;
    }
    void summ(){audioFile.printSummary();}

    private:
    std::string filename;
    AudioFile <double> audioFile;
    int framesamp;
    int fps=6;
    int data_len=1000;
    int current_sample=0;
    std::chrono::time_point<std::chrono::system_clock> start;
    double lengthInSeconds;
};