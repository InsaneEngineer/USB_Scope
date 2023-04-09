#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    camera = new Camera();
    camera->scanCams();
    ui->setupUi(this);
    for(int i = 0; i<camera->getCameraList().count();i++)
    {
      //  ui->cams->addItem(camera->getCameraList().at(i).description());
    }
    if(camera->getCameraList().count()>0)
    {
        camera->setupFirstCamera();
        setupCamera();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupCamera()
{
    camera->getCamera()->stop();
    ui->widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    supportedResolutions = camera->getCamera()->supportedViewfinderResolutions();
    camera->getCamera()->setViewfinder(ui->widget);
    ui->resolutions->clear();
    for(int i = 0; i<supportedResolutions.count(); i ++)
    {
        QString text;
        text = QString::number(supportedResolutions.at(i).width()) + "x" + QString::number(supportedResolutions.at(i).height());
        ui->resolutions->addItem(text,QVariant::fromValue(supportedResolutions.at(i)));
    }
    camera->getCamera()->start();
    //ui->widget->setAspectRatioMode(Qt::IgnoreAspectRatio);
}

void MainWindow::on_resolutions_currentIndexChanged(int index)
{
    QSize size = ui->resolutions->currentData().toSize();
    QCameraViewfinderSettings cameraSettings;
    cameraSettings.setResolution(size);
    cameraSettings.setMaximumFrameRate(camera->getCamera()->viewfinderSettings().maximumFrameRate());
    camera->getCamera()->setViewfinderSettings(cameraSettings);
}




