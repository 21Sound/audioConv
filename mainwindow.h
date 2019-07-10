#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QIcon>
#include <QLabel>
#include <QProcess>

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(int width, int height, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void fileButtonHandle();
    void folderButtonHandle();
    void processButtonHandle();

private:
    QIcon applicationIcon, fileButtonIcon, folderButtonIcon, processOffIcon, processOnIcon;

    QPushButton fileButton, folderButton, processButton;

    QPlainTextEdit statusTxt;

    QString appURI, ffmpegBinURI, inputFile, inputFolder, outputFile, outputFolder;
};

#endif // MAINWINDOW_H
