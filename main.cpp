#include "audio_manager.h"

int main(){
    audio_manager AM;
    AM.set_fps(12);
    AM.set_data_len(500);
    bool end=1;
    AM.play();
    while(end){
        //your function(AM.get_samples())
        end=AM.wait();
    }
    AM.summ();
}