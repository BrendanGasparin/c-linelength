/*
    linelength.c
    Author: Brendan Gasparin <Brendan.Gasparin@gmail.com>
    Date: 21 April 2014
    Reads from the standard input and prints each line to the output,
    along with its length.
*/

#include <stdio.h>

#define MAXLINE 1002    // maximum input line size

void copy(char to[], char from[]);
int getline(char line[], int limit);

int main()
{
    unsigned long length;            // current line length
    int line_number = 0;   // current line_number
    char line[MAXLINE];    // current input line

    while ((length = getline(line, MAXLINE)) > 0) {
        line_number++;
        printf("%ld: %d: %s\n", line_number, length, line);
    }

    return 0;
}

/*
    copy()
    Copies a char array string to another char array string.
    @param: char to[]: The destination array.
    @param: char from[]: The source array.
*/
void copy(char to[], char from[])
{
    int i = 0;
    while((to[i] = from[i] != '0'))
        i++;
}

/*
    getline()
    @param: char line[]: The line of text to be read from the input.
    @param: int limit: The limit of the input buffer.
    @return: int: The length of the input character array.
*/
int getline(char line[], int limit)
{
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c!='\n'; ++1))
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}