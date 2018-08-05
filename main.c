#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
//char * init();

char player = ' ';
int playerCount = 0;

int main(){
  bool playing = startScreen();
//  char table[][3] = init();
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
  printf("\n Welcome to Tic Tac Toe! Press any key to continue.\n");
  getchar();

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
  printf("\033c");
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
      printf("\u2014");
    }
    printf("\n %d |",i);
    for(j = 0; j < 3; j++){
      printf(" %c |", tablePtr[i][j]);
    }
  }
  printf("\n   ");
  for(k = 0; k < 13; k++){
    printf("\u2014");
  }
}

void turn(char tablePtr[][3]){
  int r = 0;
  int c = 0;
  bool picking = true;

  while(picking){
    r = row(tablePtr);
    c = col(tablePtr);
    if(tablePtr[r][c] != ' '){
      printf("\n Please pick an open square. Enter any key to try again.\n");
      picking = true;
      getchar();
      getchar();
      draw(tablePtr);
    }
    else
      picking = false;
  }


  tablePtr[r][c] = player;
}

int row(char tablePtr[][3]){
  int r = 0;
  bool picking = true;

  while(picking){
    printf("\n\n Row: ");
    scanf("%d", &r);

    if(r > 2 || r < 0){
      printf("\n Please choose between 0 and 2. Enter any key to try again.\n");
      getchar();
      getchar();
      draw(tablePtr);
    }
    else
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
      getchar();
      getchar();
      draw(tablePtr);
    }
    else
      picking = false;
  }

  return c;
}

bool checkWin(char tablePtr[][3]){
  bool won = false;

  if( (tablePtr[0][0] == 'X') && (tablePtr[1][0] == 'X') && (tablePtr[2][0] == 'X') ){
    won = true;
    draw(tablePtr);
    printf("\n X wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[0][1] == 'X') && (tablePtr[1][1] == 'X') && (tablePtr[2][1] == 'X') ){
    won = true;
    draw(tablePtr);
    printf("\n X wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[0][2] == 'X') && (tablePtr[1][2] == 'X') && (tablePtr[2][2] == 'X') ){
    won = true;
    draw(tablePtr);
    printf("\n X wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[0][0] == 'X') && (tablePtr[0][1] == 'X') && (tablePtr[0][2] == 'X') ){
    won = true;
    draw(tablePtr);
    printf("\n X wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[1][0] == 'X') && (tablePtr[1][1] == 'X') && (tablePtr[1][2] == 'X') ){
    won = true;
    draw(tablePtr);
    printf("\n X wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[2][0] == 'X') && (tablePtr[2][1] == 'X') && (tablePtr[2][2] == 'X') ){
    won = true;
    draw(tablePtr);
    printf("\n X wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[0][0] == 'X') && (tablePtr[1][1] == 'X') && (tablePtr[2][2] == 'X') ){
    won = true;
    draw(tablePtr);
    printf("\n X wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[2][0] == 'X') && (tablePtr[1][1] == 'X') && (tablePtr[0][2] == 'X') ){
    won = true;
    draw(tablePtr);
    printf("\n X wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[0][0] == 'O') && (tablePtr[1][0] == 'O') && (tablePtr[2][0] == 'O') ){
    won = true;
    draw(tablePtr);
    printf("\n O wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[0][1] == 'O') && (tablePtr[1][1] == 'O') && (tablePtr[2][1] == 'O') ){
    won = true;
    draw(tablePtr);
    printf("\n O wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[0][2] == 'O') && (tablePtr[1][2] == 'O') && (tablePtr[2][2] == 'O') ){
    won = true;
    draw(tablePtr);
    printf("\n O wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[0][0] == 'O') && (tablePtr[0][1] == 'O') && (tablePtr[0][2] == 'O') ){
    won = true;
    draw(tablePtr);
    printf("\n O wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[1][0] == 'O') && (tablePtr[1][1] == 'O') && (tablePtr[1][2] == 'O') ){
    won = true;
    draw(tablePtr);
    printf("\n O wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[2][0] == 'O') && (tablePtr[2][1] == 'O') && (tablePtr[2][2] == 'O') ){
    won = true;
    draw(tablePtr);
    printf("\n O wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[0][0] == 'O') && (tablePtr[1][1] == 'O') && (tablePtr[2][2] == 'O') ){
    won = true;
    draw(tablePtr);
    printf("\n O wins!\n");
    getchar();
    getchar();
  }

  if( (tablePtr[2][0] == 'O') && (tablePtr[1][1] == 'O') && (tablePtr[0][2] == 'O') ){
    won = true;
    draw(tablePtr);
    printf("\n O wins!\n");
    getchar();
    getchar();
  }

/* Check for a tie */
  int i,j = 0;
  bool spaceAvail = false;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      if(tablePtr[i][j] == ' ')
        spaceAvail = true;
    }
  }
  if(!spaceAvail){
    won = true;
    draw(tablePtr);
    printf("\n Cat's nest! No one wins.\n");
    getchar();
    getchar();
  }

  return won;
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
