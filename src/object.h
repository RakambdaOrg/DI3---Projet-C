#ifndef OBJECT
    #define OBJECT

    typedef struct{
        int value;
        int * weights;
    } Object;

    Object * objectCreate(void);
    void objectInitialize(Object * object, int dimensionsNumber);
    void objectSetWeight(Object * object, int weightPos, int weight);
    void objectDestroy(Object * object);

#endif
