#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSql/QtSql>
#include <QMessageBox>
#include <list>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    reserv_system = new CReservSystem("Reservas.sqlite");

    ui->setupUi(this);
    printAllReservas(reserv_system->readAllReservas());
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::printAllReservas(std::list<Reserva> lista_reservas){
    if(lista_reservas.size()==0){
        ui->tableWidget->setRowCount(0);
        return true;
    }
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->setRowCount(1);

    int i = 0;
        for(Reserva r: lista_reservas){
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(r.id_reserva));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(r.dni));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(r.nombre_paciente));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(r.especialidad_reserva));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(r.nombre_doctor));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(r.fecha));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(r.hora));

            i++;
            ui->tableWidget->insertRow(i);
        }
    return true;
}

void MainWindow::on_create_reserva_button_clicked()
{
    qDebug()<<"click create";
    Reserva new_reserva;
    new_reserva.dni = ui->dni_paciente->text();
    new_reserva.nombre_paciente = ui->nombre_paciente->text();
    new_reserva.especialidad_reserva = ui->especialidades_comboBox->currentText();
    new_reserva.nombre_doctor = "";
    new_reserva.fecha = ui->fecha_reserva->text();
    new_reserva.hora = ui->hora_comboBox->currentText();
    reserv_system->createReserva(new_reserva);

    printAllReservas(reserv_system->readAllReservas());
}


void MainWindow::on_eliminar_Button_clicked()
{
    int row = ui->tableWidget->currentRow();
    int id_reserva = ui->tableWidget->item(row,0)->text().toInt();

    reserv_system->deleteReserva(id_reserva);

    qDebug() <<"delete Reserva: "<<id_reserva;
    printAllReservas(reserv_system->readAllReservas());
}

void MainWindow::on_tableWidget_cellActivated(int row, int column)
{
    qDebug() << "selected " <<row<<" - "<<column;
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    qDebug() << "click table " <<row<<" - "<<column;
    ui->tableWidget->selectRow(row);
}



void MainWindow::on_search_especialidad_edit_textChanged(const QString &arg1)
{
    printAllReservas(
                reserv_system->searchReservasByDniEspecialidaFecha(
                    ui->seach_dni_edit->text(),
                    arg1,
                    ui->search_fecha_edit->text()
                ));
}

void MainWindow::on_search_fecha_edit_textChanged(const QString &arg1)
{
    printAllReservas(
                reserv_system->searchReservasByDniEspecialidaFecha(
                    ui->seach_dni_edit->text(),
                    ui->search_especialidad_edit->text(),
                    arg1
                ));
}

void MainWindow::on_seach_dni_edit_textChanged(const QString &arg1)
{
    printAllReservas(
                reserv_system->searchReservasByDniEspecialidaFecha(
                    arg1,
                    ui->search_especialidad_edit->text(),
                    ui->search_fecha_edit->text()
                ));
}
