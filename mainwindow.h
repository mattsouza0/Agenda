#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <pessoa.h>
#include <pessoafisica.h>
#include <pessoajuridica.h>
#include <agenda.h>
#include <QMessageBox>

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
    void on_radioButtonPessoaFisica_clicked();

    void on_radioButtonPessoajuridica_clicked();

    void on_radioButtonBuscar_Remover_clicked();

    void on_pushButtonLimpar_clicked();

    void on_pushButtonAdicionar_clicked();

    void on_pushButtonListar_clicked();

    void on_pushButtonBuscar_clicked();

    void on_pushButtonRemover_clicked();

private:
    Ui::MainWindow *ui;
    matt::Agenda agenda;
};
#endif // MAINWINDOW_H
