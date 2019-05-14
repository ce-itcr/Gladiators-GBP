#include "util.h"

int music_Counter = 0;

Util::Util()
{
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/audio/playerLoop.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);

}

void Util::playMusic(){
    cout << "changeM util " << changeMusic << endl;

    if((changeMusic == true) && (music_Counter == 0)){
        music->play();
    } else{
        music->pause();
    }
    music_Counter++;
}

void Util::pauseMusic(){

}
