#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraInfo>
class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera(QObject *parent = nullptr);
    void scanCams(void);
    void getFirstCamera(void);
    void setupCamera(QCameraInfo info);
    void setupFirstCamera(void);
    QCamera* getCamera(void);
    QList<QCameraInfo> getCameraList(void);
private:
     QList<QCameraInfo> cameras;
     void createCamera(QCameraInfo info);
     QCamera* camera;
signals:

};

#endif // CAMERA_H
