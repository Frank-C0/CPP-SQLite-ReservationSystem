#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../CReservSystem/creservsystem.h"
#include <list>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_create_reserva_button_clicked();

    bool printAllReservas(std::list<Reserva> lista_reservas);

    void on_eliminar_Button_clicked();

    void on_tableWidget_cellActivated(int row, int column);

    void on_tableWidget_cellClicked(int row, int column);

    void on_search_especialidad_edit_textChanged(const QString &arg1);

    void on_search_fecha_edit_textChanged(const QString &arg1);

    void on_seach_dni_edit_textChanged(const QString &arg1);

private:
    CReservSystem* reserv_system;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
