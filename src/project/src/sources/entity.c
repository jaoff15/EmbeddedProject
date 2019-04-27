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
void moveEntity(Entity *e, World *world, Move m){
	u8 x = e->pos.x;
	u8 y = e->pos.y;
	switch(m){
		case UP:
			/* Check that the entity is not on the top row of pixels */
			if(y < EDGE_TOP){
				if(world->cells[x][y+1] != WALL){
					/* Entity moves up */
					e->pos.y++;
				}
			}
			break;
		case DOWN:
			if(y > EDGE_BOTTOM){
				if(world->cells[x][y-1] != WALL){
					/* Entity moves down */
					e->pos.y--;
				}
			}
			break;
		case LEFT:
			if(y > EDGE_LEFT){
				if(world->cells[x-1][y] != WALL){
					/* Entity moves left */
					e->pos.x--;
				}
			}
			break;
		case RIGHT:
			if(y < EDGE_RIGHT){
				if(world->cells[x+1][y] != WALL){
					/* Entity moves right */
					e->pos.x++;
				}
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
	}
}
