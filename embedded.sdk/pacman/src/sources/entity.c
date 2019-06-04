/*
 * entity.c
 *
 *  Created on: Apr 24, 2019
 *      Author: Jacob Offersen
 */

/* Includes */
#include "../headers/entity.h"

/* Initialize entity */
void initEntity(Entity *e, EntityType type, Pos pos, Difficulty diff, Color color){
	e->type 	= type;
	e->pos 		= pos;
	e->diff 	= diff;
	e->lastMove = STANDSTILL;
	e->color    = color;
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

		/* Difficulty: Hard */
		case HARD:
			nextMove = getMoveHard(entity, world, target);
			break;

		default:
			break;
	}

	return nextMove;
}

/* Find the next move for a given entity
 * The returned move is a move in a random direction that is not backwards. */
Move getMoveEasy(Entity *entity, World *world){
	const Move 		moves[] = {UP, 		 DOWN, 		  RIGHT, 	  LEFT};
	const Pos 		dirs [] = {D_UP, 	 D_DOWN, 	  D_RIGHT,    D_LEFT};
	const u8        edges[] = {EDGE_TOP, EDGE_BOTTOM, EDGE_RIGHT, EDGE_LEFT};

	const u8 x = entity->pos.x;	// Read X
	const u8 y = entity->pos.y;	// Read Y
	Move dir[4];				// Array of directions

	dir[0] 	= (y >= edges[0] ? STANDSTILL: moves[0]);	// UP
	dir[1] 	= (y <= edges[1] ? STANDSTILL: moves[1]);	// Down
	dir[2] 	= (x >= edges[2] ? STANDSTILL: moves[2]);	// Right
	dir[3] 	= (x <= edges[3] ? STANDSTILL: moves[3]);	// Left


	for(u8 i = 0; i < 4; i++){
		dir[i] = (world->cells[x + dirs[i].x][y + dirs[i].y] == WALL ? STANDSTILL : dir[i]);	// Check walls
		if(moves[i] == UP || moves[i] == RIGHT){
			dir[i] = (entity->lastMove == moves[i+1] 				 ? STANDSTILL : dir[i]);	// Check if last move
		}else{
			dir[i] = (entity->lastMove == moves[i-1] 				 ? STANDSTILL : dir[i]);	// Check if last move
		}
	}

	/* Fill valid moves into an array and count up how many valid moves there is */
	Move validMoves[4];
	u8 validMovesCount = 0;
	for(u8 i = 0; i < 4; i++){						// For each direction
		if(dir[i] != STANDSTILL){					// If direction is valid
			validMoves[validMovesCount] = dir[i];	// Mark is as a valid move
			validMovesCount++;						// Increment valid move counter
		}
	}

	/* Select random move and return it */
	u8 i = floor( rand() % validMovesCount);
	return validMoves[i];
}



/* Return the move that gets the entity closest to the target
 * The decision to whether or not the spot is closer is based in the Euclidean distance
 * between the target and the spot being searched.
 * To enhance the performance the power and square root is not performed
 * */
Move getMoveHard(Entity *entity, World *world, Entity *target){
	const Move 		moves[] = {UP, 		 DOWN, 		  RIGHT, 	  LEFT};
	const Pos 		dirs [] = {D_UP, 	 D_DOWN, 	  D_RIGHT,    D_LEFT};
	const u8        edges[] = {EDGE_TOP, EDGE_BOTTOM, EDGE_RIGHT, EDGE_LEFT};

	const u8 x = entity->pos.x;	// Read X
	const u8 y = entity->pos.y;	// Read Y
	Move dir[4];				// Array of directions

	dir[0] 	= (y >= edges[0] ? STANDSTILL: moves[0]);	// UP
	dir[1] 	= (y <= edges[1] ? STANDSTILL: moves[1]);	// Down
	dir[2] 	= (x >= edges[2] ? STANDSTILL: moves[2]);	// Right
	dir[3] 	= (x <= edges[3] ? STANDSTILL: moves[3]);	// Left

	for(u8 i = 0; i < 4; i++){
		dir[i] = (world->cells[x + dirs[i].x][y + dirs[i].y] == WALL ? STANDSTILL : dir[i]);	// Check walls
		if(moves[i] == UP || moves[i] == RIGHT){
			dir[i] = (entity->lastMove == moves[i+1] 				 ? STANDSTILL : dir[i]);	// Check if last move
		}else{
			dir[i] = (entity->lastMove == moves[i-1] 				 ? STANDSTILL : dir[i]);	// Check if last move
		}
	}

	/* Find 'distances' and thereby the best move */
	const u8 tx = target->pos.x;					// Read target x position
	const u8 ty = target->pos.y;					// Read target y position
	f32 currentBestDist = INFTY;					// Initialize variable to keep track of best dist
	u8 currentBest = 0;								// Mark the current best distance
	for(u8 i = 0; i < 4; i++){						// For each direction
		Pos d = dirs[i];
		if(dir[i] != STANDSTILL){					// Check if it is a valid move
			u8 nx = x + d.x;
			u8 ny = y + d.y;
			u8 dist = abs(tx - nx) + abs(ty - ny);  // Get 'distance'
			if(currentBestDist >= dist){			// If distance is better than the current best
				currentBest 	= i;				// Mark move as the best
				currentBestDist = dist;				// Save current best distance
			}
		}
	}
	return dir[currentBest];						// Return best move
}



/* Move the specified entity in the specified direction (if possible)*/
void moveEntity(Entity *e, World *world, World *food, Move m){
	const Pos dirs[] = {D_STANDSTILL, D_UP, D_DOWN, D_RIGHT, D_LEFT};
	const u8 x = e->pos.x;
	const u8 y = e->pos.y;
	s8 newX = x + dirs[m].x;
	s8 newY = y + dirs[m].y;
	Move move = m;

	if(newX < EDGE_BOTTOM || newX > EDGE_TOP){
		newX = x;
		move = STANDSTILL;
	}
	if(newY < EDGE_LEFT || newY > EDGE_RIGHT){
		newY = y;
		move = STANDSTILL;
	}
	if(world->cells[newX][newY] == WALL){
		newX = x;
		newY = y;
		move = STANDSTILL;
	}

	/* Save last position and write the new position to the entity */
	e->lastPos 	= e->pos;
	e->lastMove = move;
	e->pos.x 	= newX;
	e->pos.y 	= newY;

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
	world->cells[e->pos.x][e->pos.y] = ENTITY; //( e->type == PLAYER ? ENTITY_PLAYER : ENTITY_ENEMY);
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

/* Initialize the entity list containing all entities in the world */
void initEntities(Entities *entities){
	entities->entityCount = 0;
}

/* Register a new entity to the entity list */
void registerEntity(Entities *entities, Entity *e){
	entities->entity[entities->entityCount] = e;
	entities->entityCount++;
}
