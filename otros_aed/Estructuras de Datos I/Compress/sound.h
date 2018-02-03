#ifndef SOUND_H
#define SOUND_H
#include "allegro/sound.h"
#include "allegro/system.h"
#include "allegro/keyboard.h"
class sound
{
private:
    SAMPLE *sample;
    int panning;
    int pitch;
    int volume;
public:
    sound();
    int load_Sound();
    void exit();
};

#endif // SOUND_H
