#include "header.h"

bool get_player(uint8_t** tabla, uint8_t col, int row) {
  uint8_t piece;
  
  // requires prior conversion
  convert_position(&col, &row);
  piece = tabla[row][col];

  if (piece >= 'A' && piece <= 'Z')
    return false;
  return true;
}

bool in_bounds(uint8_t** tabla, uint8_t col, int row) {
  if (col > 7 || col < 0)
    return false;
  if (row > 7 || row < 0)
    return false;
  return true;
}

bool check_basic_moving(uint8_t** tabla, uint8_t c1, int r1, uint8_t c2, int r2) {
  // requires prior conversion

  const bool current_player = get_player(tabla, c1, r1);
  const uint8_t enemy_king = (!current_player) * 32 + 'K';
  
  // check if in bounds
  if (!in_bounds(tabla, c1, r1) || !in_bounds(tabla, c2, r2))
    return false;
    
  // cannot take the place of an existing piece with the same colour
  if (current_player == get_player(tabla, c2, r2))
    return false;
    
  // can't take over the king  
  if (tabla[c2][r2] == enemy_king)
    return false;
  
  return true;
}

bool move_rook(uint8_t** tabla, uint8_t c1, int r1, uint8_t c2, int r2) {
  convert_position(&c1, &r1);
  convert_position(&c2, &r2);

  if (!check_basic_moving(tabla, c1, r1, c2, r2))
    return false;
  
  // the rook can only move on the row or on the column
  if (c1 != c2 && r1 != c2)
    return false;
    
  // pieces on the way of the move
  if (r1 == r2) {
    for (int j = c1; j <= c2; j++)
      if (tabla[r1][j] != EMPTY_PIECE)
        return false;
  }
  else
    for (int i = r1; i <= r2; i++)
      if (tabla[i][c1] != EMPTY_PIECE)
        return false;
  
  return true;
}

bool move_pawn(uint8_t** tabla, uint8_t c1, int r1, uint8_t c2, int r2) {
  convert_position(&c1, &r1);
  convert_position(&c2, &r2);
  
  const bool current_player = get_player(tabla, c1, r1);
  const int  starting_line  = 1 + current_player * 5;
  
  const int row_movement = abs(r2 - r1);
  const int col_movement = abs(c2 - c1);
  
  if (!check_basic_moving(tabla, c1, r1, c2, r2))
    return false;

  // s-a testat anterior în check_basic_movement dacă
  // pe poziția finală se află o piesă de aceeași culoare
  // sau regele inamic

  if (col_movement > 1 || row_movement > 2)
      return false;
  
  if (row_movement == 1) {
    // should take an opposite piece
    
    if (col_movement == 1 && tabla[r2][c2] == EMPTY_PIECE)
      return false;
    // can't move in front
    if (col_movement == 0 && tabla[r2][c2] != EMPTY_PIECE)
      return false;
  }
  else if (row_movement == 2) {
    const int middle_row = 1 * (-1 * current_player);
    
    if (col_movement != 0)
      return false;
    if (c1 != starting_line)
      return false;
    // clear road, please
    if (tabla[r2][c2] != EMPTY_PIECE || tabla[middle_row][c2] != EMPTY_PIECE)
      return false;
    return false;
  }
  
  return true;
}