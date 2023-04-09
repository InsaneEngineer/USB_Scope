#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <camera.h>
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


    void on_resolutions_currentIndexChanged(int index);


private:


    Ui::MainWindow *ui;
    void setupCamera();
    Camera* camera;
    QList<QSize> supportedResolutions;
};
#endif // MAINWINDOW_H
