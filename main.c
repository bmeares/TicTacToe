#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool startScreen();
bool state(char tablePtr[][3]);
void clear();
void draw(char tablePtr[][3]);
void turn(char tablePtr[][3]);
int row(char tablePtr[][3]);
int col(char tablePtr[][3]);
bool checkWin(char tablePtr[][3]);
bool yesNo();
bool runAgain();
void delay();
void randomTurn(char tablePtr[][3]);

char player = ' ';
int playerCount = 0;
int numPlayers = -1;

int main(){
  bool playing = startScreen();
  char table[3][3];
  int i = 0;
  int j = 0;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      table[i][j] = ' ';
    }
  }

  while(playing){
    playing = state(table);
    if(!playing){
      playing = runAgain();
      for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
          table[i][j] = ' ';
        }
      }
    }
  }

  return 0;
}

bool startScreen(){
  clear();
  printf("\n Welcome to Tic Tac Toe: C edition!\n\n");
  printf(" How many players for this game?\n (0, 1, or 2): ");

  while(numPlayers < 0 || numPlayers > 2){
    scanf("%d", &numPlayers);
    if(numPlayers < 0 || numPlayers > 2)
      printf("Please choose between 0 and 2.\n");
  }

  if(numPlayers < 2)
    srand(time(0));

  return true;
}

bool state(char tablePtr[][3]){
  bool playing = true;
  if((playerCount % 2) == 0)
    player = 'X';
  else
    player = 'O';

  draw(tablePtr);
  turn(tablePtr);

  playing = !checkWin(tablePtr);

  playerCount++;
  return playing;
}

void clear(){
  #ifdef __unix
//  printf("\033c");
  system("clear");
  #endif

  #ifdef _WIN32
  system("cls");
  #endif
}

void draw(char tablePtr[][3]){
  clear();

  int i,j,k = 0;
  printf("\n ");

  for(i = 0; i < 18; i++)
    printf("-");

  printf("\n | NOW PLAYING: %c |\n ", player);

  for(i = 0; i < 18; i++)
    printf("-");

  printf("\n\n     ");


  for(j = 0; j < 3; j++){
    printf("%d   ", j);
  }

  for(i = 0; i < 3; i++){

    printf("\n   ");
    for(k = 0; k < 13; k++){
      printf("-");
    }
    printf("\n %d |",i);
    for(j = 0; j < 3; j++){
      printf(" %c |", tablePtr[i][j]);
    }
  }
  printf("\n   ");
  for(k = 0; k < 13; k++){
    printf("-");
  }
  printf("\n");
}

void turn(char tablePtr[][3]){
  int r = 0;
  int c = 0;
  bool picking = true;

  if (numPlayers == 2 || ((player == 'X') && (numPlayers == 1)) ){
    while(picking){
      r = row(tablePtr);
      c = col(tablePtr);
      if(tablePtr[r][c] != ' '){
        printf("\n Please pick an open square. Enter any key to try again.\n");
        picking = true;
        while ((getchar()) != '\n');
        getchar();
        draw(tablePtr);
      } else
          picking = false;
    }
    tablePtr[r][c] = player;
  } else if(numPlayers < 2)
      randomTurn(tablePtr);
}

void randomTurn(char tablePtr[][3]){
  int r,c = 0;
  bool picking = true;

  while(picking){
    r = rand() % 3;
    c = rand() % 3;
    if(tablePtr[r][c] != ' '){
      picking = true;
    } else
        picking = false;
  }
  tablePtr[r][c] = player;
  delay(500000);

}

int row(char tablePtr[][3]){
  int r = 0;
  bool picking = true;

  while(picking){
    printf("\n\n Row: ");
    scanf("%d", &r);

    if(r > 2 || r < 0){
      printf("\n Please choose between 0 and 2. Enter any key to try again.\n");
      while ((getchar()) != '\n');
      getchar();
      draw(tablePtr);
    } else
        picking = false;
  }

  return r;
}

int col(char tablePtr[][3]){
  int c = 0;

  bool picking = true;

  while(picking){
    printf("\n Column: ");
    scanf("%d", &c);

    if(c > 2 || c < 0){
      printf("\n Please choose between 0 and 2. Enter any key to try again.\n");
      while ((getchar()) != '\n');
      getchar();
      draw(tablePtr);
    } else
        picking = false;
  }

  return c;
}

bool checkWin(char tablePtr[][3]){
  int i,j;
  char first, second, third;

  /* Check for horizontal victory */
  for(i = 0; i < 3; i++){
    first = tablePtr[i][0];
    second = tablePtr[i][1];
    third = tablePtr[i][2];

    if( (first == second) && (second == third) && (first != ' ') ) {
      draw(tablePtr);
      printf("\n %c wins!\n", first);
      while ((getchar()) != '\n');
      getchar();
      return true;
    }
  }

  /* Check for vertical victory */
  for(i = 0; i < 3; i++){
    first = tablePtr[0][i];
    second = tablePtr[1][i];
    third = tablePtr[2][i];

    if( (first == second) && (second == third) && (first != ' ')){
      draw(tablePtr);
      printf("\n %c wins!\n", first);
      while ((getchar()) != '\n');
      getchar();
      return true;
    }
  }

  /* Check for diagonal victory */
  if( (((tablePtr[0][0] == tablePtr[1][1]) &&
  (tablePtr[1][1] == tablePtr[2][2])) || (tablePtr[2][0] == tablePtr[1][1]) &&
  (tablePtr[1][1] == tablePtr[0][2])) && tablePtr[1][1] != ' ' ){
    draw(tablePtr);
    printf("\n %c wins!\n", tablePtr[1][1]);
    while ((getchar()) != '\n');
    getchar();
    return true;
  }

  /* Check for tie */
  bool spaceAvail = false;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      if(tablePtr[i][j] == ' ')
        spaceAvail = true;

  if(!spaceAvail){
    spaceAvail = false;
    draw(tablePtr);
    printf("\n Cat's nest! No one wins.\n");
    while ((getchar()) != '\n');
    getchar();
    return true;
  }
  return false;
}

bool yesNo(){
  char y = ' ';
  bool yes = false;
  scanf("%c", &y);
  if(y == 'y' || y == 'Y')
    yes = true;
  return yes;
}

bool runAgain(){
  clear();
  printf("\n Run again? (y/n) ");
  return yesNo();
}

void delay(unsigned int mseconds){
    #ifdef _WIN32
    mseconds /= 1000;
    #endif

    clock_t goal = mseconds + clock();
    while (goal > clock());
}
