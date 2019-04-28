/*
 * entity.c
 *
 *  Created on: Apr 24, 2019
 *      Author: Jacob Offersen
 */

/* Includes */
#include "../headers/entity.h"

/* Initialize entity */
void initEntity(Entity *e, EntityType type, Pos pos, Difficulty diff){
	e->type 	= type;
	e->pos 		= pos;
	e->diff 	= diff;
	e->lastMove = STANDSTILL;
}

/* Control entity.
 * Only used for entities that are not manually controlled */
Move controlEntity(Entity *entity, World *world, Entity *target){
	Move nextMove = STANDSTILL;			// Default move

	switch(entity->diff){
		/* Difficulty: Easy */
		case EASY:
			nextMove = getMoveEasy(entity, world);
			break;

		/* Difficulty: Medium */
		case MEDIUM:
			break;

		/* Difficulty: Hard */
		case HARD:
			break;

		/* Difficulty: Impossible */
		case IMPOSSIBLE:
			break;

		default:
			break;
	}

	return nextMove;
}

/* Find the next move for a given entity
 * The returned move is a move in a random direction that is not backwards. */
Move getMoveEasy(Entity *entity, World *world){
	u8 x = entity->pos.x;
	u8 y = entity->pos.y;
	Move dir[4];
	/* Can the entity move up */
	dir[0] 	= (y < EDGE_TOP    && world->cells[x][y+1] != WALL ? UP : STANDSTILL);

	/* Can the entity move down */
	dir[1] 	= (y > EDGE_BOTTOM && world->cells[x][y-1] != WALL ? DOWN : STANDSTILL);

	/* Can the entity move left */
	dir[2] 	= (x > EDGE_LEFT   && world->cells[x-1][y] != WALL ? LEFT : STANDSTILL);

	/* Can the entity move right */
	dir[3] 	= (x < EDGE_RIGHT  && world->cells[x+1][y] != WALL ? RIGHT : STANDSTILL);


	/* If entity cannot move */
	if(!(dir[0] || dir[1] || dir[2] || dir[3])){
		return STANDSTILL;
	}

	/* Remove possibility for moving back */
	dir[0] = (entity->lastMove == DOWN 	? STANDSTILL : dir[0]);
	dir[1] = (entity->lastMove == UP	? STANDSTILL : dir[1]);
	dir[2] = (entity->lastMove == RIGHT ? STANDSTILL : dir[2]);
	dir[3] = (entity->lastMove == LEFT 	? STANDSTILL : dir[3]);


	/* Select random move from possible moves */
	Move moves[4];
	u8 index = 0;
	for(u8 i = 0; i < 4; i++){
		if(dir[i]){
			moves[index] = dir[i];
			index++;
		}
	}
	/* Get random move */
	u8 i = floor( rand() % index );
	return moves[ i ];
}


/* Move the specified entity in the specified direction (if possible)*/
void moveEntity(Entity *e, World *world, World *food, Move m){
	u8 x = e->pos.x;
	u8 y = e->pos.y;
	u8 newX = x;
	u8 newY = y;
	switch(m){
		case UP:
			/* Check that the entity is not on the top row of pixels */
			if(y < EDGE_TOP){
				/* Move the entity if there is not wall on the new position */
				newY 		= (world->cells[x][y+1] != WALL ? y+1 : y);

				/* Save the move in the entity */
				e->lastMove = ( newY > y ? UP : STANDSTILL);
			}
			break;
		case DOWN:
			if(y > EDGE_BOTTOM){
				/* Move the entity if there is not wall on the new position */
				newY 		= (world->cells[x][y-1] != WALL ? y-1 : y);

				/* Save the move in the entity */
				e->lastMove = ( newY < y ? DOWN : STANDSTILL);
			}
			break;
		case LEFT:
			if(x > EDGE_LEFT){
				/* Move the entity if there is not wall on the new position */
				newX 		= (world->cells[x-1][y] != WALL ? x-1 : x);

				/* Save the move in the entity */
				e->lastMove = ( newX < x ? LEFT : STANDSTILL);
			}
			break;
		case RIGHT:
			if(x < EDGE_RIGHT){
				/* Move the entity if there is not wall on the new position */
				newX 		= (world->cells[x+1][y] != WALL ? x+1 : x);

				/* Save the move in the entity */
				e->lastMove = ( newX > x ? RIGHT : STANDSTILL);
			}
			break;
		case STANDSTILL:
			/* Entity stays where it is */
			e->lastMove = STANDSTILL;
			break;
		default:
			/* Entity stays where it is */
			e->lastMove = STANDSTILL;
			break;
	}

	/* Save last position and write the new position to the entity */
	e->lastPos = e->pos;
	e->pos.x = newX;
	e->pos.y = newY;

	/* If the entity is a player and is moving into a cell with food.
	 * Increment the players score */
	if(e->type == PLAYER && world->cells[e->pos.x][e->pos.y] == FOOD){
		incrementScore();
		food->cells[e->pos.x][e->pos.y] = NONE;
		printf("Score: %d\n",getScore());
	}
}


/* Load the parsed entity into the world */
void loadEntity(Entity *e,World *world){
	/* If player type is player then write 'player' into the world. Otherwise write 'enemy'*/
	world->cells[e->pos.x][e->pos.y] = ( e->type == PLAYER ? ENTITY_PLAYER : ENTITY_ENEMY);
}


/* Check if the specified entity has been killed by any of it's enemies */
bool entityKilled(Entity *e, Entity *enemy){
	bool killed = FALSE;
	/* If the entity is in the same block as an enemy.
	 * Return 'killed'*/
	if(e->pos.x == enemy->pos.x && e->pos.y == enemy->pos.y){
		killed = TRUE;
	}
	/* If the entity and its enemy has just swapped positions they crossed each others paths
	 * return 'killed' */
	if( e->lastPos.x == enemy->pos.x && e->lastPos.y == enemy->pos.y &&
		enemy->lastPos.x == e->pos.x && enemy->lastPos.y == e->pos.y){
		killed = TRUE;
	}
	/* If the entity was not killed.
	 * return 'not killed' */
	return killed;
}
