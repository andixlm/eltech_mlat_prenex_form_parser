#include "mainwindow.h"
#include "parser.h"

int idx;
const char* stringToAnalyze;
bool isResultCorrect;

void ignoreSpaces()
{
  while (stringToAnalyze[idx] == ' ')
    ++idx;
}

bool MainWindow::parse()
{
  idx = 0;
  stringToAnalyze = this->string;
  isResultCorrect = true;

  prenexForm();

  if (stringToAnalyze[idx] != '\0')
    isResultCorrect = false;

  return isResultCorrect;
}

void prenexForm()
{
  if (isQuantifier(stringToAnalyze[idx])) {
    ++idx, ignoreSpaces();

    variable();
    prenexForm();

  } else if (stringToAnalyze[idx] == '(') {
    ++idx, ignoreSpaces();

    prenexForm();

    if (stringToAnalyze[idx++] != ')')
      isResultCorrect = false;

    // Formula
  } else if (stringToAnalyze[idx] == 'P' && stringToAnalyze[idx + 1] == '(') {
    idx += 2, ignoreSpaces();

    argument();
  } else {
    isResultCorrect = false;
  }
}

void variable()
{
  if (stringToAnalyze[idx] == 'x') {
    ++idx, ignoreSpaces();
    index();

  } else {
    isResultCorrect = false;
  }
}

void index()
{
  if (stringToAnalyze[idx] == '[') {
    ++idx, ignoreSpaces();
    number();
  }
}

void number()
{
  if (isDigit(stringToAnalyze[idx]) && isNonZeroDigit(stringToAnalyze[idx])) {
    ++idx, ignoreSpaces();

    digitsSequence();

  } else if (stringToAnalyze[idx] == '0' && stringToAnalyze[idx + 1] == ']') {
    idx += 2, ignoreSpaces();

  } else {
    isResultCorrect = false;
  }
}

void digitsSequence()
{
  if (isDigit(stringToAnalyze[idx])) {
    ++idx, ignoreSpaces();

    digitsSequence();

  } else if (stringToAnalyze[idx] == ']') {
    ++idx, ignoreSpaces();

  } else {
    isResultCorrect = false;
  }
}

void argument()
{
  if (stringToAnalyze[idx] == 'x') {
    variable();
    divider();

  } else {
    isResultCorrect = false;
  }
}

void divider()
{
  if (stringToAnalyze[idx] == ';') {
    ++idx, ignoreSpaces();
    argument();

  } else if (stringToAnalyze[idx] == ')') {
    ++idx, ignoreSpaces();

  } else {
    isResultCorrect = false;
  }
}
