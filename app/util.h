#ifndef UTIL_H
#define UTIL_H

#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <iostream>

using namespace std;

class Util
{
private:
public:
    Util();
    QMediaPlayer * music;
    void playMusic();
    void playSpell();
    void playClick();
    bool changeMusic = true;

};

#endif // UTIL_H
