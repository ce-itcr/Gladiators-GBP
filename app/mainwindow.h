/**
 * @file mainwindow.h
 * @version 1.0
 * @date 19/04/19 -
 * @authors angelortizv
 * @title Ventana de Inicio.
 * @brief Corresponde a la ventana de Bienvenida, redirecciona al juego, a las configuraciones y a logros.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "achievements.h"
#include "pregame.h"
#include "util.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void on_settings_Button_clicked();

    void on_play_Button_clicked();

    void on_achievements_Button_clicked();

    void on_exit_Button_clicked();

//    void on_info_Button_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
