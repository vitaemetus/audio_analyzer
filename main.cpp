#include "audio_manager.h"
#include "print.h"

int main(){
    audio_manager AM("/Users/furs/audio_analyzer/test.wav");
    AM.set_fps(12);
    AM.set_data_len(500);
    bool end=1;
    AM.play();
    //while(end){
    //     print(AM.get_samples());
    //     end=AM.wait();
    // }
    AM.summ();
}