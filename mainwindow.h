#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cmap.h"
#include "c_config.h"
#include "c_camera.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    CMap *map;

    bool isPressed;
    void initCameras();
protected:
    void wheelEvent(QWheelEvent *event);
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *);
    void keyPressEvent(QKeyEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private slots:
    void on_lineEdit_returnPressed();
    void readPendingDatagrams();
    void updateCameras();
private:

    double mLat,mLon;
    double mScale;
    Ui::MainWindow *ui;
    QPoint pressPos;
    int dxMap;
    int dyMap;

    void drawCrossHairMark(int x, int y, QPainter *p);
    void LoadSettings();
    void drawMap(QPainter *p);
    void drawCameras(QPainter *p);
    int lon2x(double lon);
    int lat2y(double lat);

    void initSocket();

    void processUdpData(QByteArray buffer);
};

#endif // MAINWINDOW_H
