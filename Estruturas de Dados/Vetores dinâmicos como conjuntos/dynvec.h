#ifndef DYNVEC_H
#define DYNVEC_H

typedef struct dynvec DynVec;

    DynVec *dv_create();
    DynVec *dv_create_from_file(const char *filename);
    void dv_insert(DynVec *dv, float x);
    int dv_is_in(DynVec *dv, float x);
    float dv_get(DynVec *dv, int i);
    int dv_size(DynVec *dv);
    int dv_capacity(DynVec *dv);
    void dv_free(DynVec *dv);
    void dv_print_values(DynVec *dv);
    void dv_write_to_file(DynVec *dv, const char *filename);
    DynVec *dv_concatenate(DynVec *dv1, DynVec *dv2);
    DynVec *dv_union(DynVec *dv1, DynVec *dv2);
    DynVec *dv_intersection(DynVec *dv1, DynVec *dv2);
    DynVec *dv_unique(DynVec *dv);

#endif