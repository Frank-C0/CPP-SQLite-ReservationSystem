#ifndef CRESERVSYSTEM_H
#define CRESERVSYSTEM_H

#include <list>
#include <QString>
#include <QtSql/QtSql>

struct Reserva{
    QString id_reserva;
    QString dni;
    QString nombre_paciente;
    QString especialidad_reserva;
    QString nombre_doctor;
    QString fecha;
    QString hora;
    Reserva();

    static int n_id_reserva;
    static int n_dni;
    static int n_paciente;
    static int n_especialidad;
    static int n_doctor;
    static int n_fecha;
    static int n_hora;
};


class CReservSystem
{
private:
    QSqlDatabase db;
    bool createTables();
public:
    CReservSystem(QString);
    bool createReserva(Reserva r);
    bool deleteReserva(int id);
    std::list<Reserva> readAllReservas();
    std::list<Reserva> searchReservasByDniEspecialidaFecha(QString,QString,QString);
    static QString getDoctor(QString);
    static QString getHoraReserva(QString, QString);
};

#endif // CRESERVSYSTEM_H
