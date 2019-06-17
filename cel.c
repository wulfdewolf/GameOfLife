#include "header.h"


/*                                                                    *
*                                                                     *
*                                 CEL                                 *
*                                                                     *
*                                                                     */


struct cel* make_cel(int curr, char team, int next){			// creates a cel
	struct cel* c = malloc(sizeof(struct cel));
	c->curr = curr;
	c->team = team;
	c->next = next;
	return c;
};


void next_to_curr(struct cel** c){												// shifts a given cel from curr to next
	(*c)->curr = (*c)->next;
};


char celchar(struct cel c){																// gets a cel team character
	if (c.curr == 0){
		return ' ';
	}	else return c.team;
};


void print_cel(struct cel** c){														// prints a given cel to terminal
	printf("%c", celchar(**c));
};
