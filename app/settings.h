/**
 * @file settings.h
 * @version 1.0
 * @date 19/04/19 -
 * @authors angelortizv
 * @title Ventana de Configuraciones Principales.
 * @brief Incluye configuraciones como: cambio de sonido y tamaño de población.
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "util.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private slots:
    void on_toMainWindow_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
