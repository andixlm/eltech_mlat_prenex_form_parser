#include <string>
#include "mainwindow.h"
#include "parser.h"
#include "ui_mainwindow.h"

const QString emptyResult = "-";
const QString correctResult = "верно";
const QString incorrectResult = "неверно";

void MainWindow::on_clearButton_clicked()
{
  ui->computedResultLabel->setText(emptyResult);
  ui->textField->clear();

  if (this->string != nullptr)
    delete this->string;
  this->string = nullptr;
}

void MainWindow::on_checkButton_clicked()
{
  if (this->string != nullptr)
    delete this->string;
  this->string = nullptr;

  // Gotta use painful C strings.
  // There's no need to delete C string we got, innerString does it.
  std::string innerString = ui->textField->toPlainText().toStdString();
  this->string = innerString.c_str();

  if (this->string != nullptr && parse()) {
    ui->computedResultLabel->setText(correctResult);
  } else {
    ui->computedResultLabel->setText(incorrectResult);
  }

  this->string = nullptr;
}
