#include "sound.h"

sound::sound()
{
    //sample;
    panning = 128;
    pitch = 1000;
    volume = 500;
}
int sound::load_Sound()
{
    /*if (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0)
    {
        allegro_message("Error initializing sound system");
        return 1;
    }*/
    sample = load_sample("sonido.wav");
    /*if (!sample)
    {
        allegro_message("Error reading wave file");
        return 1;
    }*/
    play_sample(sample, volume, panning, pitch, TRUE);
}
void sound::exit()
{
    destroy_sample(sample);
    remove_sound();
}
