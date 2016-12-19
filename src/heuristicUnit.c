#include <stdlib.h>
#include "heuristicUnit.h"
#include "heuristic.h"
#include "parser.h"
#include "unit.h"
#include "instance.h"
#include "scheduler.h"

void heuristicTests()
{
    Instance * instance = parser_readAllFile("MKP-Instances/theBestBag.txt");
    Bag * bag = bag_create(instance);

    int * correctList = scheduler_itemValue(instance);
    int * list = heuristic_getList(instance, bag, 1);
    if(!unit_arrayEquals(correctList, list, instance->itemsCount))
        unit_error("ASSERT HEURISTIC 1");
    free(correctList);
    free(list);
    correctList = scheduler_ratioAllDimensions(instance);
    list = heuristic_getList(instance, bag, 2);
    if(!unit_arrayEquals(correctList, list, instance->itemsCount))
        unit_error("ASSERT HEURISTIC 2");
    free(correctList);
    free(list);
    correctList = scheduler_ratioForDimension(instance, bag_getCriticDimension(instance, bag), NULL, instance->itemsCount);
    list = heuristic_getList(instance, bag, 3);
    if(!unit_arrayEquals(correctList, list, instance->itemsCount))
        unit_error("ASSERT HEURISTIC 3");
    free(correctList);
    free(list);

    Solution * solution = heuristic(instance, 0, 0);
    if(solution->type != INDIRECT)
        unit_error("ASSERT HEURISTIC 4");
    heuristic_solutionDestroy(solution);
    solution = heuristic(instance, 1, 0);
    if(solution->type != DIRECT)
        unit_error("ASSERT HEURISTIC 5");
    heuristic_solutionDestroy(solution);

    instance_destroy(instance);
    free(instance);
}
