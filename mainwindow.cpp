#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->textEdit->setDisabled(true);
    ui->lineEditNome->setDisabled(true);
    ui->lineEditEndereco->setDisabled(true);
    ui->lineEditEmail->setDisabled(true);
    //pf
    ui->lineEditCPF->setDisabled(true);
    ui->lineEditDataNascimento->setDisabled(true);
    ui->lineEditEstadoCivil->setDisabled(true);
    //pj
    ui->lineEditCNPJ->setDisabled(true);
    ui->lineEditInscricaoEstadual->setDisabled(true);
    ui->lineEditRazaoSocial->setDisabled(true);
    //buttons
    ui->pushButtonBuscar->setDisabled(true);
    ui->pushButtonListar->setDisabled(true);
    ui->pushButtonRemover->setDisabled(true);
    ui->pushButtonAdicionar->setDisabled(true);
    //buscar_remover
    ui->lineEditBuscar_Remover->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButtonPessoaFisica_clicked()
{
    ui->lineEditNome->setDisabled(false);
    ui->lineEditEndereco->setDisabled(false);
    ui->lineEditEmail->setDisabled(false);
    ui->lineEditCPF->setDisabled(false);
    ui->lineEditDataNascimento->setDisabled(false);
    ui->lineEditEstadoCivil->setDisabled(false);
    ui->pushButtonListar->setDisabled(false);
    ui->pushButtonAdicionar->setDisabled(false);

    ui->lineEditCNPJ->setDisabled(true);
    ui->lineEditInscricaoEstadual->setDisabled(true);
    ui->lineEditRazaoSocial->setDisabled(true);
}

void MainWindow::on_radioButtonPessoajuridica_clicked()
{
    ui->lineEditNome->setDisabled(false);
    ui->lineEditEndereco->setDisabled(false);
    ui->lineEditEmail->setDisabled(false);
    ui->lineEditCNPJ->setDisabled(false);
    ui->lineEditInscricaoEstadual->setDisabled(false);
    ui->lineEditRazaoSocial->setDisabled(false);
    ui->pushButtonListar->setDisabled(false);
    ui->pushButtonAdicionar->setDisabled(false);

    ui->lineEditCPF->setDisabled(true);
    ui->lineEditDataNascimento->setDisabled(true);
    ui->lineEditEstadoCivil->setDisabled(true);
}

void MainWindow::on_radioButtonBuscar_Remover_clicked()
{
    ui->lineEditBuscar_Remover->setDisabled(false);
    ui->pushButtonBuscar->setDisabled(false);
    ui->pushButtonRemover->setDisabled(false);
}

void MainWindow::on_pushButtonLimpar_clicked()
{
    ui->lineEditNome->clear();
    ui->lineEditEmail->clear();
    ui->lineEditEndereco->clear();
    ui->lineEditCPF->clear();
    ui->lineEditDataNascimento->clear();
    ui->lineEditCNPJ->clear();
    ui->lineEditInscricaoEstadual->clear();
    ui->lineEditRazaoSocial->clear();
    ui->lineEditBuscar_Remover->clear();
    ui->lineEditEstadoCivil->clear();
    ui->textEdit->clear();
}

void MainWindow::on_pushButtonAdicionar_clicked()
{
    matt::Pessoa *pessoa;
    try {
        QString nome = ui->lineEditNome->text();
        QString endereco = ui->lineEditEndereco->text();
        QString email = ui->lineEditEmail->text();
        if(ui->radioButtonPessoaFisica->isChecked()){
            QString cpf = ui->lineEditCPF->text();
            int dataNascimento = ui->lineEditDataNascimento->text().toInt();
            QString estadocivil = ui->lineEditEstadoCivil->text();
            pessoa = new matt::PessoaFisica(nome,endereco,email,cpf,dataNascimento,estadocivil);
            agenda.inserirContato(pessoa);
            QMessageBox::information(this,"Contato Adicionado",pessoa->print());
        }
        else if (ui->radioButtonPessoajuridica->isChecked()) {
            QString cnpj = ui->lineEditCNPJ->text();
            long long inscricaoEstadual = ui->lineEditInscricaoEstadual->text().toLongLong();
            QString razaoSocial = ui->lineEditRazaoSocial->text();
            pessoa = new matt::PessoaJuridica(nome,endereco,email,cnpj,inscricaoEstadual,razaoSocial);
            agenda.inserirContato(pessoa);
            QMessageBox::information(this,"Contato Adicionado",pessoa->print());
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonListar_clicked()
{
    try {
        ui->textEdit->setText(agenda.listar());
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        QString doc = ui->lineEditBuscar_Remover->text();
        QString saida;
        if(doc.isEmpty()){
            QMessageBox::information(this,"ERRO","Não foi informado nenhum documento");
        }
        saida = agenda.buscarContato(doc);
        QMessageBox::information(this,"Contato Encontrado",saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonRemover_clicked()
{
    try {
        QString doc = ui->lineEditBuscar_Remover->text();
        agenda.removerContato(doc);
        QMessageBox::information(this,"Agenda","Contato Removido");
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
