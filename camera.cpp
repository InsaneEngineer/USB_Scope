#include "camera.h"

Camera::Camera(QObject *parent) : QObject(parent)
{

}
void Camera::scanCams()
{
    cameras = QCameraInfo::availableCameras();
}
QList<QCameraInfo> Camera::getCameraList()
{
    return cameras;
}
void Camera::createCamera(QCameraInfo info)
{
    camera = new QCamera(info);
}
void Camera::setupCamera(QCameraInfo info)
{
    if(camera == nullptr)
    {
        delete camera;
        createCamera(info);
    }
    else
    {
        createCamera(info);
    }
}
void Camera::setupFirstCamera()
{
    this->setupCamera(cameras.first());
}
QCamera* Camera::getCamera()
{
    return camera;
}
