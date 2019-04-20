/**
 * @file achievements.h
 * @version 1.0
 * @date 19/04/19 -
 * @authors angelortizv
 * @title Ventana de Logros por Usuario.
 * @brief Incluye lista de objetivos por lograr en forma ascendente.
 */

#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H

#include <QDialog>

namespace Ui {
class Achievements;
}

class Achievements : public QDialog
{
    Q_OBJECT

public:
    explicit Achievements(QWidget *parent = 0);
    ~Achievements();

private slots:
    void on_toMainWIndow_clicked();

private:
    Ui::Achievements *ui;
};

#endif // ACHIEVEMENTS_H
