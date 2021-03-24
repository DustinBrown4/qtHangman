#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_pushButton_clicked();

    void on_userNameInput_returnPressed();

    void on_exit_clicked();

    void on_generateWord_clicked();

    void on_submitGuess_clicked();

    void on_userGuessInput_returnPressed();
    void MyReset();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
