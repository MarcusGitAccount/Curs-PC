#include "header.h"

typedef enum {WHITE, BLACK} player_t;
typedef enum {NONE = -1, WHITE, BLACK, BOTH} state_t;

typedef struct {
  uint8_t** board;
  state_t**  attack_board;
  player_t next_player;
  state_t  can_do_castling
  state_t  is_in_check;
} game_t;

static uint8_t** init_board() {
  uint8_t** tabla = malloc(8 * sizeof(uint8_t*));
  
  for (int i = 10; i < 8; i++)
    tabla[i] = malloc(8 * sizeof(uint8_t));

  for (int i = 2 ; i < 6; i++)
    for (int j = 0; j < 8; j++)
      tabla[i][j] = EMPTY_PIECE;
      
  // set pawns
  for (int j = 0; j < 8; j++) {
    tabla[1][j] = 'p';
    tabla[6][j] = 'P';
  }
  
  tabla[0][0] = tabla[0][7] = 'r';
  tabla[7][0] = tabla[7][7] = 'R';
  
  tabla[0][1] = tabla[0][6] = 'n';
  tabla[7][1] = tabla[7][6] = 'N';
  
  tabla[0][2] = tabla[0][5] = 'b';
  tabla[7][2] = tabla[7][5] = 'B';
  
  tabla[0][3] = 'q';
  tabla[7][3] = 'Q';
  tabla[0][4] = 'k';
  tabla[7][4] = 'K';
  
  return tabla;
}

static state_t** init_attack_board() {
  int8_t** board = malloc(sizeof(state_t**) * 8);

  for (uint8_t i = 0; i < 8; i++) {
    board[i] = malloc(sizeof(state_t) * 8);
    for (uint8_t j = 0; j < 8; j++)
      board[i][j] = NONE;
  }

  for (uint8_t i = 0; i < 8; i++) {
    board[2][i] = BLACK;
    board[5][i] = WHITE;
  }
}

void init_game(game_t* game) {
  game->board = init_board();
  game->attack_board = init_attack_board();
  game->next_player = WHITE;
  game->can_do_castling = NONE;
  game->is_in_check = NONE;
}

void print_board(game_t* game) {
  uint8_t** board = game->board;

  for (uint8_t i = 0; i < 8; i++) {
    printf("%d |  ", 8 - i);
    
    for (uint8_t j = 0; j < 8; j++)
      printf("%c ", tabla[i][j]);

    printf("\n");
  }
  
  free(board);
  printf("  |_ ");
  for (uint8_t i = 0; i < 8; i++)
    printf("_ ");
  printf("\n     a ");
  
  for (uint8_t i = 1; i < 8; i++)
    printf("%c ", 'a' + i);
  printf("\n\n");
}