#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED


//A vector array
typedef struct vector_ {
    void** data;
    int size;
    int count;
} vector;

//You must initalize a vector before using one.
void vector_init(vector*);

//Returns the amount of elements in a vector.
int vector_count(vector*);

//Adds another element to the end of the vector.
void vector_add(vector*, void*);

//Set a vectors element based off of the index.
void vector_set(vector*, int, void*);

//Returns a vector element.
void* vector_get(vector*, int);

//Erases a single element from the index provided.
void vector_erase(vector*, int);

//Removes a vector from memory. Execute this when finished using a vector.
void vector_free(vector*);

#endif // VECTOR_H_INCLUDED
