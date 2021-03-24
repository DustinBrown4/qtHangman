#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileReader.h"
#include "wordCheck.h"
#include  <string>

using namespace std;
wordCheck wordChecker;
FileReader word;
string wordA = word.sendWord();
QString userWord = QString::fromStdString(wordA);
string correct;
QString correctLetters;
QString incorrectLetters;
unsigned short int i;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_userNameInput_returnPressed()
{
    //take user input for name. hide form once entered
    QString input = ui->userNameInput->text();
    ui->usernameLabel->setText(input);
    ui->userNameInput->hide();
    ui->enterUserNameLabel->hide();
    ui->generateWord->click();
}

void MainWindow::on_pushButton_clicked()
{
    QString input = ui->userNameInput->text();
    ui->usernameLabel->setText(input);
}

void MainWindow::on_exit_clicked()
{
    close();
}

void MainWindow::on_generateWord_clicked()
{
//generates word  from filereader

    QString currentWord= "";
    string wordA = word.sendWord();
    unsigned short int size = wordA.size();
    userWord = QString::fromStdString(wordA);

    correct.resize(userWord.size());
    for (i=0;i < correct.size(); ++i){
        correct.at(i) = '?';
    }

    currentWord = QString::fromStdString(correct);
    //clear generated word when clicked after a word has already been created including wrong and correct
    ui->correctLetters->clear();
    ui->wrongLetters->clear();

    ui->generatedWord->setText(currentWord);
}

void MainWindow::on_submitGuess_clicked()
{
    //submits guess to wordCheck
    //converts qt and cpp
    QString guess = ui->userGuessInput->text();
    string myWord = userWord.toStdString();
    string myGuess = guess.toStdString();

    //check for incorrect
    string incorrect = wordChecker.WrongGuess(myGuess, myWord);

    //populate correct guesses
    string function = wordChecker.CorrectGuess(myGuess, myWord);
    for(i=0; i < myWord.size(); ++i){
        if (myWord.at(i) == myGuess[0]){
            correct.at(i) = myGuess[0];
        }
    }

    //outputs
    correctLetters = QString::fromStdString(correct);
    incorrectLetters = incorrectLetters.append(QString::fromStdString(incorrect));
    ui->correctLetters->setText(correctLetters);
    ui->wrongLetters->setText(incorrectLetters);
    ui->generatedWord->setText("");
    //clears input
    ui->userGuessInput->clear();

}

void MainWindow::on_userGuessInput_returnPressed()
{
    //submits guess to wordCheck
    //converts qt and cpp
    QString guess = ui->userGuessInput->text();
    string myWord = userWord.toStdString();
    string myGuess = guess.toStdString();

    //check for incorrect
    string incorrect = wordChecker.WrongGuess(myGuess, myWord);

    //populate correct guesses
    string function = wordChecker.CorrectGuess(myGuess, myWord);
    for(i=0; i < myWord.size(); ++i){
        if (myWord.at(i) == myGuess[0]){
            correct.at(i) = myGuess[0];
        }
    }

    //outputs
    correctLetters = QString::fromStdString(correct);
    incorrectLetters = incorrectLetters.append(QString::fromStdString(incorrect));
    ui->correctLetters->setText(correctLetters);
    ui->wrongLetters->setText(incorrectLetters);
    ui->generatedWord->setText("");
    //clears input
    ui->userGuessInput->clear();
}

//reset slot. Clears username, generates new word, clears correct letters, clears wrong characters
 void MainWindow::MyReset(){
    ui->correctLetters->clear();
    ui->wrongLetters->clear();
    ui->usernameLabel->clear();
    ui->userNameInput->clear();
    string wordA = word.sendWord();
    userWord = QString::fromStdString(wordA);

    correct.resize(userWord.size());
    for (i=0;i < correct.size(); ++i){
        correct.at(i) = '?';
    }

    QString currentWord = QString::fromStdString(correct);

    ui->generatedWord->setText(currentWord);
    ui->userNameInput->show();
    ui->enterUserNameLabel->show();
}


