#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    areTrainsRunning = false;

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1, 120, 90);
    trem2 = new Trem(2, 320, 30);
    trem3 = new Trem(3, 480, 90);
    trem4 = new Trem(4, 240, 270);
    trem5 = new Trem(5, 370, 270);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    connect(trem2, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    connect(trem3, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    connect(trem4, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    connect(trem5, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
  switch(id){
    case 1:
        ui->label_trem1->setGeometry(x,y,21,17);
        break;

    case 2:
        ui->label_trem2->setGeometry(x,y,21,17);
        break;

    case 3:
        ui->label_trem3->setGeometry(x,y,21,17);
        break;

    case 4:
        ui->label_trem4->setGeometry(x,y,21,17);
        break;

    case 5:
        ui->label_trem5->setGeometry(x,y,21,17);
        break;

    default:
        break;
  }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 */
void MainWindow::on_pushButton_clicked()
{
    areTrainsRunning = true;

    trem1->start();
    trem1->setOffset(trem1->getVelocidade() >= SLIDER_MAXIMUM_VALUE ? 0 : Trem::DEFAULT_OFFSET);

    trem2->start();
    trem2->setOffset(trem2->getVelocidade() >= SLIDER_MAXIMUM_VALUE ? 0 : Trem::DEFAULT_OFFSET);

    trem3->start();
    trem3->setOffset(trem3->getVelocidade() >= SLIDER_MAXIMUM_VALUE ? 0 : Trem::DEFAULT_OFFSET);

    trem4->start();
    trem4->setOffset(trem4->getVelocidade() >= SLIDER_MAXIMUM_VALUE ? 0 : Trem::DEFAULT_OFFSET);

    trem5->start();
    trem5->setOffset(trem5->getVelocidade() >= SLIDER_MAXIMUM_VALUE ? 0 : Trem::DEFAULT_OFFSET);
}

/*
 * Ao clicar, trens param execução
 */
void MainWindow::on_pushButton_2_clicked()
{
    areTrainsRunning = false;

    trem1->stopTrem();
    trem2->stopTrem();
    trem3->stopTrem();
    trem4->stopTrem();
    trem5->stopTrem();
}

void MainWindow::on_slider_trem1_valueChanged(int value)
{
  trem1->startTrem();

  if (trem1->isRunning() && !areTrainsRunning) {
    trem1->stopTrem();
  }

  trem1->setVelocidade(SLIDER_MAXIMUM_VALUE - value);

  if (value == 0 && areTrainsRunning) {
    trem1->stopTrem();
  }
}

void MainWindow::on_slider_trem2_valueChanged(int value)
{
  trem2->startTrem();

  if (trem2->isRunning() && !areTrainsRunning) {
    trem2->stopTrem();
  }

  trem2->setVelocidade(SLIDER_MAXIMUM_VALUE - value);

  if (value == 0 && areTrainsRunning) {
    trem2->stopTrem();
  }
}

void MainWindow::on_slider_trem3_valueChanged(int value)
{
  trem3->startTrem();

  if (trem3->isRunning() && !areTrainsRunning) {
    trem3->stopTrem();
  }

  trem3->setVelocidade(SLIDER_MAXIMUM_VALUE - value);

  if (value == 0 && areTrainsRunning) {
    trem3->stopTrem();
  }
}

void MainWindow::on_slider_trem4_valueChanged(int value)
{
  trem4->startTrem();

  if (trem4->isRunning() && !areTrainsRunning) {
    trem4->stopTrem();
  }

  trem4->setVelocidade(SLIDER_MAXIMUM_VALUE - value);

  if (value == 0 && areTrainsRunning) {
    trem4->stopTrem();
  }
}

void MainWindow::on_slider_trem5_valueChanged(int value)
{
  trem5->startTrem();

  if (trem5->isRunning() && !areTrainsRunning) {
    trem5->stopTrem();
  }

  trem5->setVelocidade(SLIDER_MAXIMUM_VALUE - value);

  if (value == 0 && areTrainsRunning) {
    trem5->stopTrem();
  }
}
