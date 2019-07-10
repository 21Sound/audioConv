#include <QCoreApplication>
#include <QFileDialog>

#include <QThread>

#include "mainwindow.h"

MainWindow::MainWindow(int width, int height, QWidget *parent)
    : QMainWindow(parent) {

    appURI = QCoreApplication::applicationDirPath();

    ffmpegBinURI = appURI + QString("/ffmpeg/bin/ffmpeg.exe");

    QString tmpStr = appURI + QString("/symbols/logo01.png");
    applicationIcon.addFile(tmpStr);

    tmpStr = appURI + QString("/symbols/fileIcon.png");
    fileButtonIcon.addFile(tmpStr);

    tmpStr = appURI + QString("/symbols/folderIcon.png");
    folderButtonIcon.addFile(tmpStr);

    tmpStr = appURI + QString("/symbols/processOffIcon.png");
    processOffIcon.addFile(tmpStr);

    tmpStr = appURI;
    tmpStr.append("/symbols/processOnIcon.png");
    processOnIcon.addFile(tmpStr);

    appURI = QCoreApplication::applicationDirPath();

    this->resize(width, height);

    this->setWindowIcon(applicationIcon);
    this->setWindowTitle("FFmpeg based audio Converter");
    this->setAcceptDrops(false);

    fileButton.setParent(this);
    fileButton.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    fileButton.setIcon(fileButtonIcon);
    fileButton.move(width/20, height/20);
    fileButton.resize(width/10, height/10);
    fileButton.setIconSize(0.8*fileButton.size());

    folderButton.setParent(this);
    folderButton.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    folderButton.setIcon(folderButtonIcon);
    folderButton.move(4*width/20, height/20);
    folderButton.resize(width/10, height/10);
    folderButton.setIconSize(0.8*folderButton.size());

    processButton.setParent(this);
    processButton.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    processButton.setIcon(processOffIcon);
    processButton.move(17*width/20, height/20);
    processButton.resize(width/10, height/10);
    processButton.setIconSize(0.8*processButton.size());
    processButton.setEnabled(false);

    statusTxt.setParent(this);
    statusTxt.move(width/20, 11*height/20);
    statusTxt.resize(18*width/20, 8*height/20);
    statusTxt.setPalette(this->palette());
    statusTxt.viewport()->setAutoFillBackground(false);
    statusTxt.setReadOnly(true);
    statusTxt.setMaximumBlockCount(25);

    statusTxt.appendPlainText("ffmpeg path: " + ffmpegBinURI + QString("\n"));

    statusTxt.appendPlainText("Please start by either choosing an input file or path via the appropriate buttons.");

    connect(&fileButton, SIGNAL (clicked()), this, SLOT(fileButtonHandle()));
    connect(&folderButton, SIGNAL (clicked()), this, SLOT(folderButtonHandle()));
    connect(&processButton, SIGNAL (clicked()), this, SLOT(processButtonHandle()));
}

void MainWindow::fileButtonHandle() {
    statusTxt.appendPlainText("fileButtonHandle: Clicked." + QString("\n"));

    inputFile = QFileDialog::getOpenFileName(this, appURI);
    outputFile = inputFile.left(inputFile.lastIndexOf(".")) + QString("_out.mp3");
    processButton.setEnabled(true);

    statusTxt.appendPlainText("Actual processing file: " + inputFile + QString("\n"));
}

void MainWindow::folderButtonHandle() {
    statusTxt.appendPlainText("folderButtonHandle: Clicked." + QString("\n"));

    inputFolder = QFileDialog::getExistingDirectory(this, appURI);
    outputFolder = QFileDialog::getExistingDirectory(this, appURI) + QString("_out.mp3");
    processButton.setEnabled(true);

    statusTxt.appendPlainText("Actual processing folder: " + inputFolder + QString("\n"));
}

void MainWindow::processButtonHandle() {
    statusTxt.appendPlainText("processButtonHandle: Clicked." + QString("\n"));
    statusTxt.repaint();

    processButton.setIcon(processOnIcon);
    processButton.repaint();

    const QString command = ffmpegBinURI + QString(" -y -i \"" + inputFile + "\" \"") + outputFile + QString("\"");
    QProcess::execute(command);

    processButton.setIcon(processOffIcon);
    processButton.repaint();

    statusTxt.appendPlainText("Processing done.\n");
}

MainWindow::~MainWindow(){

}
