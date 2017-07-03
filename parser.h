#ifndef PARSER_H
#define PARSER_H

void prenexForm();
void quantifier();
void variable();
void index();
void number();
void digitsSequence();
void formula();
void argument();
void divider();

void ignoreSpaces();

bool isQuantifier(char symbol);
bool isDigit(char symbol);
bool isNonZeroDigit(char symbol);

#endif // PARSER_H
