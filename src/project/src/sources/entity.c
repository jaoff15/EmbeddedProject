/*
 * entity.c
 *
 *  Created on: Apr 24, 2019
 *      Author: jacoboffersen
 */

/* Includes */
#include "../headers/entity.h"

/* Initialize entity */
void initEntity(Entity *e, EntityType type, Pos pos){
	e->type = type;
	e->pos = pos;
}

/* Control entity.
 * This function is only used for entities that are not manually controlled */
void controlEntity(Entity *e, Move *m){

}

/* Move the specified entity in the specified direction (if possible)*/
void moveEntity(Entity *e, World *world, World *food, Move m){
	u8 x = e->pos.x;
	u8 y = e->pos.y;
	switch(m){
		case UP:
			/* Check that the entity is not on the top row of pixels */
			if(y < EDGE_TOP){
				e->pos.y = world->cells[x][y+1] != WALL ? y+1 : y;
//				if(world->cells[x][y+1] != WALL){
//					/* Entity moves up */
//					e->pos.y++;
//				}
			}
			break;
		case DOWN:
			if(y > EDGE_BOTTOM){
				e->pos.y = (world->cells[x][y-1] != WALL ? y-1 : y);
//				if(world->cells[x][y-1] != WALL){
//					/* Entity moves down */
//					e->pos.y--;
//				}
			}
			break;
		case LEFT:
			if(x > EDGE_LEFT){
				e->pos.x =  world->cells[x-1][y] != WALL ? x-1 : x;
//				if(world->cells[x-1][y] != WALL){
//					/* Entity moves left */
//					e->pos.x--;
//				}
			}
			break;
		case RIGHT:
			if(x < EDGE_RIGHT){
				e->pos.x =  world->cells[x+1][y] != WALL ? x+1 : x;
//				if(world->cells[x+1][y] != WALL){
//					/* Entity moves right */
//					e->pos.x++;
//				}
			}
			break;
		case NONE:
			/* Entity stays where it is */
			break;
		default:
			/* Entity stays where it is */
			break;
	}

	/* If the entity is a player and is moving into a cell with food.
	 * Increment the players score */
	if(e->type == PLAYER && world->cells[e->pos.x][e->pos.y] == FOOD){
		incrementScore();
		food->cells[e->pos.x][e->pos.y] = NONE;
		printf("Score: %d\n",getScore());
	}
}

void loadEntity(Entity *e,World *world){
	/* If player type is player then write 'player' into the world. Otherwise write 'enemy'*/
	world->cells[e->pos.x][e->pos.y] = ( e->type == PLAYER ? ENTITY_PLAYER : ENTITY_ENEMY);
}




