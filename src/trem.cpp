#include "trem.h"
#include "mainwindow.h"

#include <QMutex>
#include <QSemaphore>

QMutex blueRedRegion;
QMutex redPurpleRegion;
QMutex bluePurpleRegion;
QMutex orangePurpleRegion;
QMutex redOrangeRegion;
QMutex greenOrangeRegion;
QMutex redGreenRegion;

QSemaphore blueRedPurpleRegion(2);
QSemaphore redPurpleOrangeRegion(2);
QSemaphore redGreenOrangeRegion(2);

QSemaphore blueRedPurpleOrangeRegion(3);
QSemaphore redGreenPurpleOrangeRegion(3);

QSemaphore rainbowRegion(4);

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = 100;
    this->offset = DEFAULT_OFFSET;
}

//Função a ser executada após executar trem->START
void Trem::run(){
  while(true) {
    switch(ID) {
      case 1:
        if (y == 30 && x < 250) {
          x += offset;

          if (x == 230 && !isTremStopped()) {
            rainbowRegion.acquire();
            blueRedPurpleOrangeRegion.acquire();
            blueRedPurpleRegion.acquire();
            blueRedRegion.lock();
          }
        } else if (x == 120 && y > 30) {
          y -= offset;
        } else if (x > 120 && y == 150) {
          x -= offset;

          if (x == 160 && !isTremStopped()) {
            bluePurpleRegion.unlock();
            blueRedPurpleRegion.release();
            blueRedPurpleOrangeRegion.release();
            rainbowRegion.release();
          }

          if (x == 230 && !isTremStopped()) {
            blueRedRegion.unlock();
          }
        } else {
          y += offset;

          if (y == 130 && !isTremStopped()) {
            bluePurpleRegion.lock();
          }
        }
        emit updateGUI(ID, x, y);
        break;

      case 2:
        if (y == 30 && x < 370) {
          x += offset;

          if (x == 350 && !isTremStopped()) {
            rainbowRegion.acquire();
            redGreenPurpleOrangeRegion.acquire();
            redGreenOrangeRegion.acquire();
            redGreenRegion.lock();
          }

          if (x == 270 && !isTremStopped()) {
            blueRedRegion.unlock();
            blueRedPurpleRegion.release();
            blueRedPurpleOrangeRegion.release();
            rainbowRegion.release();
          }
        } else if (x == 250 && y > 30) {
          y -= offset;

          if (y == 130 && !isTremStopped()) {
            redPurpleRegion.unlock();
            redPurpleOrangeRegion.release();
            redGreenPurpleOrangeRegion.release();
          }
        } else if (x > 250 && y == 150) {
          x -= offset;

          if (x == 350 && !isTremStopped()) {
            redGreenRegion.unlock();
          }

          if (x == 330 && !isTremStopped()) {
            blueRedPurpleRegion.acquire();
            redPurpleRegion.lock();
          }

          if (x == 290 && !isTremStopped()) {
            redOrangeRegion.unlock();
            redGreenOrangeRegion.release();
          }

          if (x == 270 && !isTremStopped()) {
            blueRedRegion.lock();
          }
        } else {
          y += offset;

          if (y == 130 && !isTremStopped()) {
            blueRedPurpleOrangeRegion.acquire();
            redPurpleOrangeRegion.acquire();
            redOrangeRegion.lock();
          }
        }
        emit updateGUI(ID, x, y);
        break;

      case 3:
        if (y == 30 && x < 480) {
          x += offset;

          if (x == 390 && !isTremStopped()) {
            redGreenRegion.unlock();
            redGreenOrangeRegion.release();
            redGreenPurpleOrangeRegion.release();
            rainbowRegion.release();
          }
        } else if (x == 370 && y > 30) {
          y -= offset;

          if (y == 130 && !isTremStopped()) {
            greenOrangeRegion.unlock();
          }
        } else if (x > 370 && y == 150) {
          x -= offset;

          if (x == 440 && !isTremStopped()) {
            rainbowRegion.acquire();
            redGreenPurpleOrangeRegion.acquire();
            redGreenOrangeRegion.acquire();
            greenOrangeRegion.lock();
          }

          if (x == 390 && !isTremStopped()) {
            redGreenRegion.lock();
          }
        } else {
          y += offset;
        }
        emit updateGUI(ID, x, y);
        break;

      case 4:
        if (y == 150 && x < 310) {
          x += offset;

          if (x == 290 && !isTremStopped()) {
            orangePurpleRegion.lock();
          }

          if (x == 270 && !isTremStopped()) {
            bluePurpleRegion.unlock();
          }

          if (x == 230 && !isTremStopped()) {
            redGreenPurpleOrangeRegion.acquire();
            redPurpleOrangeRegion.acquire();
            redPurpleRegion.lock();
          }
        } else if (x == 180 && y > 150) {
          y -= offset;

          if (y == 170 && !isTremStopped()) {
            rainbowRegion.acquire();
            blueRedPurpleOrangeRegion.acquire();
            blueRedPurpleRegion.acquire();
            bluePurpleRegion.lock();
          }
        } else if (x > 180 && y == 270) {
          x -= offset;

          if (x == 290 && !isTremStopped()) {
            orangePurpleRegion.unlock();
            redPurpleOrangeRegion.release();
            blueRedPurpleOrangeRegion.release();
            redGreenPurpleOrangeRegion.release();
            rainbowRegion.release();
          }
        } else {
          y += offset;

          if (y == 170 && !isTremStopped()) {
            redPurpleRegion.unlock();
            blueRedPurpleRegion.release();
          }
        }
        emit updateGUI(ID, x, y);
        break;

      case 5:
        if (y == 150 && x < 420) {
          x += offset;

          if (x == 390 && !isTremStopped()) {
            redOrangeRegion.unlock();
            redPurpleOrangeRegion.release();
            blueRedPurpleOrangeRegion.release();
          }

          if (x == 350 && !isTremStopped()) {
            greenOrangeRegion.lock();
          }

          if (x == 330 && !isTremStopped()) {
            orangePurpleRegion.unlock();
          }
        } else if (x == 310 && y > 150) {
          y -= offset;

          if (y == 170 && !isTremStopped()) {
            redGreenOrangeRegion.acquire();
            redOrangeRegion.lock();
          }
        } else if (x > 310 && y == 270) {
          x -= offset;

          if (x == 330 && !isTremStopped()) {
            rainbowRegion.acquire();
            redGreenPurpleOrangeRegion.acquire();
            blueRedPurpleOrangeRegion.acquire();
            redPurpleOrangeRegion.acquire();
            orangePurpleRegion.lock();
          }
        } else {
          y += offset;

          if (y == 170 && !isTremStopped()) {
            greenOrangeRegion.unlock();
            redGreenOrangeRegion.release();
            redGreenPurpleOrangeRegion.release();
            rainbowRegion.release();
          }
        }
        emit updateGUI(ID, x, y);
        break;

      default:
        break;
    }

    msleep(velocidade);
  }
}

void Trem::setVelocidade(int velocidade) {
  this->velocidade = velocidade;
}

int Trem::getVelocidade() {
  return this->velocidade;
}

void Trem::setOffset(int offset) {
  this->offset = offset;
}

void Trem::stopTrem() {
  this->offset = 0;
}

void Trem::startTrem() {
  this->offset = DEFAULT_OFFSET;
}

bool Trem::isTremStopped() {
  return this->offset == 0;
}
