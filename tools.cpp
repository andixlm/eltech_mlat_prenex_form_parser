#include "parser.h"

bool isQuantifier(char symbol)
{
  switch (symbol)
  {
    case 'A': case 'E':
      return true;

    default:
      return false;
  }
}

bool isDigit(char symbol)
{
  switch (symbol)
  {
    case '0':
    case '1': case '2': case '3':
    case '4': case '5': case '6':
    case '7': case '8': case '9':
      return true;

    default:
      return false;
  }
}

bool isNonZeroDigit(char symbol)
{
  switch (symbol)
  {
    case '1': case '2': case '3':
    case '4': case '5': case '6':
    case '7': case '8': case '9':
      return true;

    default:
      return false;
  }
}
