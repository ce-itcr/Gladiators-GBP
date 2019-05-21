#include "util.h"

int music_Counter = 0;

Util::Util(){
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/audio/theme.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->setVolume(100);
}

void Util::playMusic(){

    if((changeMusic == true) && (music_Counter == 0)){
        music->play();
    } else{
        music->pause();
    }
    music_Counter++;
}

void Util::playSpell(){
    QMediaPlayer* spellAudio = new QMediaPlayer;
    spellAudio->setMedia(QUrl("qrc:/audio/magic2.flac"));
    spellAudio->setVolume(150);
    spellAudio->play();
}

void Util::playClick(){
    QMediaPlayer* spellAudio = new QMediaPlayer;
    spellAudio->setMedia(QUrl("qrc:/audio/click.mp3"));
    spellAudio->setVolume(150);
    spellAudio->play();
}
