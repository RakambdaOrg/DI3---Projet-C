#include <stdlib.h>
#include <stdio.h>

#include "instanceUnit.h"
#include "instance.h"

void instanceTests()
{
	int * weights = (int *) malloc(3 * sizeof(int));
	if(weights == NULL)
		exit(10);
	weights[0] = 1;
	weights[1] = 2;
	weights[2] = 3;
	
	Instance * instance;
	if((instance = (Instance *) malloc(sizeof(Instance))) == NULL)
	{
		perror("TEST MALLOC ERROR");
		exit(EXIT_FAILURE);
	}
	instance_initialize(instance, 0, 0);
	if(instance->items != NULL || instance->maxWeights != NULL)
	{
		perror("ASSERT INSTANCE 2");
		exit(EXIT_FAILURE);
	}
	if(instance_getItem(instance, 2) != NULL)
	{
		perror("ASSERT INSTANCE 3");
		exit(EXIT_FAILURE);
	}
	instance_initialize(instance, 3, 3);
	instance->maxWeights = weights;
	if(instance->items == NULL || instance_getItem(instance, 2)->value != 0)
	{
		perror("ASSERT INSTANCE 4");
		exit(EXIT_FAILURE);
	}
	if(instance_getItem(instance, 3) != NULL)
	{
		perror("ASSERT INSTANCE 5");
		exit(EXIT_FAILURE);
	}
	instance_destroy(instance);
	free(instance);
}
