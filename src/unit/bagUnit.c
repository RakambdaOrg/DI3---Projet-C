#include <stdlib.h>
#include "headers/unit.h"
#include "headers/bagUnit.h"
#include "../headers/bag.h"
#include "../headers/parser.h"

void bagTests()
{
	Instance * instance = parser_readAllFile("MKP-Instances/theBestBag.txt");
	Bag * bag = bag_create(instance);
	
	if(bag->itemsCount != 0)
		unit_error("ASSERT BAG 1");
	if(bag_getWeight(bag, 0) != 0 || bag_getWeight(bag, 1) != 0)
		unit_error("ASSERT BAG 2");
	if(bag_canContain(instance, bag, 2) != 0 || bag_canContain(instance, bag, 5) != 0 || bag_canContain(instance, bag, 4) != 0)
		unit_error("ASSERT BAG 3");
	if(bag_canContain(instance, bag, 0) != 1 || bag_canContain(instance, bag, 12) != 1)
		unit_error("ASSERT BAG 4");
	bag_addWeight(bag, 1, 100);
	if(bag_getWeight(bag, 1) != 100)
		unit_error("ASSERT BAG 5");
	bag_addWeight(bag, 1, -100);
	if(bag_getWeight(bag, 1) != 0)
		unit_error("ASSERT BAG 6");
	bag_appendItem(instance, bag, 12);
	if(bag->itemsCount != 1 || bag_getItemIndex(bag, 0) != 12)
		unit_error("ASSERT BAG 7");
	if(bag_getWeight(bag, 0) != 1 || bag_getWeight(bag, 1) != 6)
		unit_error("ASSERT BAG 8");
	if(bag_getCriticDimension(instance, bag) != 0)
		unit_error("ASSERT BAG 9");
	bag_appendItem(instance, bag, 1);
	if(bag->itemsCount != 2 || bag_getItemIndex(bag, 1) != 1)
		unit_error("ASSERT BAG 10");
	if(bag_getWeight(bag, 0) != 5 || bag_getWeight(bag, 1) != 94)
		unit_error("ASSERT BAG 11");
	
	char * filename = "testBag.txt";
	FILE * file;
	if((file = fopen(filename, "w+")) == NULL)
	{
		perror("ERROR FOPEN BAG UNIT");
		exit(EXIT_FAILURE);
	}
	bag_saveItems(bag, file);
	fseek(file, 0, SEEK_SET);
	char * line = parser_readLine(file);
	int * bagItems = parser_lineToIntArray(line, bag->itemsCount);
	free(line);
	fclose(file);
	if(remove(filename) != 0)
		perror("ERROR REMOVE BAG UNIT");
	for(int i = 0; i < bag->itemsCount; i++)
		if(bagItems[i] != bag_getItemIndex(bag, i))
			unit_error("ASSERT BAG 12");
	free(bagItems);
	
	SolutionDirect * solutionDirect = bag_toSolutionDirect(instance, bag);
	int itemsTaken[15] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
	if(!unit_arrayEquals(itemsTaken, solutionDirect->itemsTaken, instance->itemsCount))
		unit_error("ASSERT BAG 13");
	solutionDirect_destroy(solutionDirect);
	
	bag_destroy(bag);
	instance_destroy(instance);
}
