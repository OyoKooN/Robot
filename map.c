#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/constants.h"
#include "headers/appartU.h"
#include "headers/map.h"
#include "headers/robot.h"

/*
 * Read the map from the header and store it in memory 
 *
 * @return Map strcuture
 */
Map read_map() {
  
  Map map;
  
  memcpy(map.map, appart, MAP_WIDTH * MAP_HEIGHT);
  map.width = MAP_WIDTH;
  map.height = MAP_HEIGHT;
  
  return map;

}

/*
 * Show the map with the robot
 *
 */
void show_map(Map map, Robot bot) {

  int i = 0, j = 0;

  printf("\n");
  
  for (i = 0; i < map.height; i++) {
  
    for (j = 0; j < map.width; j++) {
    
      if (bot.posY == i && bot.posX == j) {
       printf("%c", bot.name); 
      }
      else if (map.map[i][j] == 'x' || map.map[i][j] == 'S') {
        printf("%c", map.map[i][j]);
      }
      else if (bot.m[i][j] == 1) {
        printf("*");
      }
      else {
      printf(" ");
      }
    
    }
    printf("\n");
    
  }
  
  printf("\n");
  
}

/*
 * Find the exit coordinates of the map
 *
 * @return Exit structure
 */
Exit find_map_exit(Map map) {

  int i = 0, j = 0;
  Exit exit;
  
  for (i = 0; i < map.height; i++) {
  
    for (j = 0; j < map.width; j++) {
    
      if (map.map[i][j] == 'S') {
        exit.y = i;
        exit.x = j;
      }
      
    }
    
  }
  
  return exit;

}
