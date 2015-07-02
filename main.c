#include	<string.h>
#include	<stdlib.h>

char		*head;
char		*middle;
char		*bottom;

typedef struct	s_number_image
{
  char		*head;
  char		*middle;
  char		*bottom;
}		t_number_image;

t_number_image	images[] = {
  {" _ ", "| |", "|_|"},
  {"   ", " | ", " | "},
  {" _ ", " _|", "|_ "},
  {" _ ", " _|", " _|"},
  {"   ", "|_|", "  |"},
  {" _ ", "|_ ", " _|"},
  {" _ ", "|_ ", "|_|"},
  {" _ ", "  |", "  |"},
  {" _ ", "|_|", "|_|"},
  {" _ ", "|_|", " _|"},
};

int		length(char *str)
{
  return (strlen(str));
}

void		displayLine(char *str)
{
  write(1, str, length(str));
  write(1, "\n", 1);
}

void		drawNumber(char *bodyPart, int numberPosition, char *numberImage)
{
  bodyPart[numberPosition * 3] = numberImage[0];
  bodyPart[numberPosition * 3 + 1] = numberImage[1];
  bodyPart[numberPosition * 3 + 2] = numberImage[2]; 
}

void		drawNumberBody(int numberPosition, int number)
{
  drawNumber(head, numberPosition, images[number].head);
  drawNumber(middle, numberPosition, images[number].middle);
  drawNumber(bottom, numberPosition, images[number].bottom);
}

int		main()
{
  int		numberPosition = 8;
  int		numberToDisplay = 667755345;	
  int		currentNumber;


  head = malloc(3 * 9);
  middle = malloc(3 * 9);
  bottom = malloc(3 * 9);

  while (numberPosition >= 0)
    {
      currentNumber = numberToDisplay % 10;
      drawNumberBody(numberPosition, currentNumber);
      numberToDisplay /= 10;
      numberPosition--;
    }

  displayLine(head);
  displayLine(middle);
  displayLine(bottom);
  return (0);
}
