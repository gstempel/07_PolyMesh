#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main(int argc, char **argv) {

  screen s;
  struct matrix * edges;
  struct matrix * transform;
  struct matrix * polygons;

  clear_screen(s);
  color c;
  c.red = 0;
  c.green = 255;
  c.blue = 255;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  polygons = new_matrix(4,4);

  add_polygon(polygons, 0, 250, 0, 250, 0, 0, 0, 0, 0);
  draw_polygons(polygons, s, c);
  display(s);
  /* print_matrix( make_bezier() ); */
  /* printf("\n"); */
  /* print_matrix( make_hermite() ); */

  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );

  
  free_matrix( edges );
  free_matrix( transform );
}  
