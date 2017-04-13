#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_SIZE 128

typedef struct {
  int width, height;
  int alt[MAX_SIZE][MAX_SIZE];
  char id[MAX_SIZE][MAX_SIZE];
} map_t;

enum {North = 0, West, East, South, nDirs};

const int dirs[nDirs][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

map_t*
new_map(int width, int height)
{
  map_t *map = calloc(sizeof(map_t), 1);
  int x, y;

  map->width = width;
  map->height = height;
  
  /* sentinel */
  for (x = 1; x <= width; x++) {
    map->alt[0][x] = map->alt[height + 1][x] = INT_MAX;
  }
  for (y = 1; y <= height; y++) {
    map->alt[y][0] = map->alt[y][width + 1] = INT_MAX;
  }
  return map;
}

int
follow(map_t *map, int x, int y, char id)
{
  char *stack = malloc(sizeof(char) * map->width * map->height);
  int stackp;
  int dir;
  int lowest;
  int lowest_dir = -1;
  int new_sink = 0;

  assert(x >= 0 && x < map->width);
  assert(y >= 0 && y < map->height);

  x++; y++;

  if (map->id[y][x]) return 0;

  lowest = map->alt[y][x];
  stackp = 0;
  do {
    lowest_dir = -1;
    for (dir = North; dir < nDirs; dir++) {
      int dx = x + dirs[dir][0];
      int dy = y + dirs[dir][1];
      if (lowest > map->alt[dy][dx]) {
	lowest = map->alt[dy][dx];
	lowest_dir = dir;
      }
    }
    if (lowest_dir >= 0) {
      x += dirs[lowest_dir][0];
      y += dirs[lowest_dir][1];
      stack[stackp++] = lowest_dir;
    }
  } while (lowest_dir >= 0 && map->id[y][x] == 0);

  if (map->id[y][x]) {
    id = map->id[y][x];
  } else {
    new_sink = 1;
    map->id[y][x] = id;
  }
  
  while (stackp) {
    dir = stack[--stackp];
    x -= dirs[dir][0];
    y -= dirs[dir][1];
    map->id[y][x] = id;
  }

  free(stack);
  return new_sink;
}

void
read_map(map_t *map, FILE *in)
{
  int x, y;
  int alt;
  char buffer[0x400];
  char *p;
  for (y = 0; y < map->height; y++) {
    if (fgets(buffer, sizeof(buffer), in) == NULL) {
      fprintf(stderr, "failed to fgets()\n");
    }
    p = buffer;
    for (x = 0; x < map->width; x++) {
      alt = strtol(p, &p, 0);
      map->alt[y + 1][x + 1] = alt;
    }
  }
}

void
write_map_label(map_t *map, FILE *out)
{
  int x, y;
  for (y = 0; y < map->height; y++) {
    for (x = 0; x < map->width; x++) {
      fprintf(out, "%c ", map->id[y + 1][x + 1]);
    }
    fputc('\n', out);
  }
}

void
write_map_alt(map_t *map, FILE *out)
{
  int x, y;
  for (y = 0; y < map->height; y++) {
    for (x = 0; x < map->width; x++) {
      fprintf(out, "%5d ", map->alt[y + 1][x + 1]);
    }
    fputc('\n', out);
  }
}

void
calc(map_t *map)
{
  int x,y;
  int id = 'a';
  for (y = 0; y < map->height; y++) {
    for (x = 0; x < map->width; x++) {
      if (follow(map, x, y, id)) {
	id++;
      }
    }
  }
}

int
main()
{
  int height, width;
  int n_cases, i;
  map_t *map;

  scanf("%d\n", &n_cases);

  for (i = 0; i < n_cases; i++) {
    printf("Case #%d:\n", i + 1);
    if (scanf("%d %d\n", &height, &width) != 2) {
      fprintf(stderr, "Illegal size\n");
    }
    map = new_map(width, height);
    read_map(map, stdin);
    calc(map);
    write_map_label(map, stdout);
    free(map);
  }

  return 0;
}
