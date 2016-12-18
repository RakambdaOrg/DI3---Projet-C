#ifndef SCHEDULER
#define SCHEDULER

#include "instance.h"

int * scheduler_random(Instance * instance);

/**
 * Remove an item from the list.
 *
 * @param listPtr A pointer to the list to remove from.
 * @param listCount A pointer to the size of the list.
 * @param index The index of the item to remove.
 * @return The popped element.
 */
int scheduler_removeFromList(int ** listPtr, int * listCount, int index);

void scheduler_appendToList(int ** list, int * listCount, int element);

int * scheduler_itemValue(Instance * instance);

int * scheduler_ratioAllDimensions(Instance * instance);

double scheduler_getRatioAllDimensions(Instance * instance, int index);

int * scheduler_ratioForDimension(Instance * instance, int dimension, int * itemsInList, int sizeList);

double scheduler_getRatio(Instance * instance, int index, int dim);

int * scheduler_ratioAllDimensionsWeighted(Instance * instance);

double scheduler_getRatioAllDimensionsWeighted(Instance * instance, int index);

#endif
