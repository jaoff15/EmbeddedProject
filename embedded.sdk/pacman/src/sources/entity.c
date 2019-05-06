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

	/* Remove possibility for moving backwards */
	dir[0] = (entity->lastMove == DOWN 	? STANDSTILL : dir[0]);
	dir[1] = (entity->lastMove == UP	? STANDSTILL : dir[1]);
	dir[2] = (entity->lastMove == RIGHT ? STANDSTILL : dir[2]);
	dir[3] = (entity->lastMove == LEFT 	? STANDSTILL : dir[3]);


	/* Fill the possible moves into an array and count up how many valid moves there is */
	Move moves[4];
	u8 index = 0;
	for(u8 i = 0; i < 4; i++){
		if(dir[i]){
			moves[index] = dir[i];
			index++;
		}
	}

	/* Select random move and return it */
	u8 i = floor( rand() % index );
	return moves[ i ];
}

/* Return the move that gets the entity closest to the target
 * The decision to whether or not the spot is closer is based in the Euclidean distance
 * between the target and the spot being searched.
 * To enhance the performance the power and square root is not performed
 * */
Move getMoveHard(Entity *entity, World *world, Entity *target){
	const u8 x = entity->pos.x;
	const u8 y = entity->pos.y;
	Move dir[4];
	/* Can the entity move up */
	dir[0] 	= (y < EDGE_TOP    && world->cells[x][y+1] != WALL ? UP : STANDSTILL);

	/* Can the entity move down */
	dir[1] 	= (y > EDGE_BOTTOM && world->cells[x][y-1] != WALL ? DOWN : STANDSTILL);

	/* Can the entity move left */
	dir[2] 	= (x > EDGE_LEFT   && world->cells[x-1][y] != WALL ? LEFT : STANDSTILL);

	/* Can the entity move right */
	dir[3] 	= (x < EDGE_RIGHT  && world->cells[x+1][y] != WALL ? RIGHT : STANDSTILL);

	/* Remove possibility for moving backwards */
	dir[0] = (entity->lastMove == DOWN 	? STANDSTILL : dir[0]);
	dir[1] = (entity->lastMove == UP	? STANDSTILL : dir[1]);
	dir[2] = (entity->lastMove == RIGHT ? STANDSTILL : dir[2]);
	dir[3] = (entity->lastMove == LEFT 	? STANDSTILL : dir[3]);

	/* If entity cannot move */
	if(!(dir[0] || dir[1] || dir[2] || dir[3])){
		return STANDSTILL;
	}

	/* Find 'distances' and thereby the best move */
	f32 tx = target->pos.x;
	f32 ty = target->pos.y;
	f32 distance[4] = {INFTY,INFTY,INFTY,INFTY};
	u8 currentBest = 0;
	for(u8 i = 0; i < 4; i++){
		if(dir[i] != STANDSTILL){
			switch(dir[i]){
			case UP:
				distance[i] = (abs((tx - x)*(tx - x))     + abs((ty - y-1.0)*(ty - y-1.0)));
				break;
			case DOWN:
				distance[i] = (abs((tx - x)*(tx - x))     + abs((ty - y+1.0)*(ty - y+1.0)));
				break;
			case LEFT:
				distance[i] = (abs((tx - x+1.0)*(tx - x+1.0)) + abs((ty - y)*(ty - y)));
				break;
			case RIGHT:
				distance[i] = (abs((tx - x-1.0)*(tx - x-1.0)) + abs((ty - y)*(ty - y)));
				break;
			default:
				distance[i] = INFTY;
				break;
			}
			if(distance[currentBest] >= distance[i]){
				currentBest = i;
			}
		}else{
			distance[i] = INFTY;
		}
	}
	return dir[currentBest];
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
