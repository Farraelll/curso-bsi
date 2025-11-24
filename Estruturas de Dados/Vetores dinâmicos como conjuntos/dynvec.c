#include "dynvec.h" 
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct dynvec
{
   int n;     
   int n_max; 
   float *v;  
};

DynVec *dv_create()
{
   DynVec *dv = (DynVec *)malloc(sizeof(DynVec)); 
   dv->n = 0;                                          
   dv->n_max = 4;                                      
   dv->v = (float *)malloc(dv->n_max * sizeof(float)); 
   return dv; 
}

DynVec *dv_create_from_file(const char *filename)
{
   FILE *f = fopen(filename, "rt"); 
   if (f == NULL)
      return NULL; 

   DynVec *dv = dv_create();
   float x;
   while (fscanf(f, "%f", &x) == 1) 
      dv_insert(dv, x);

   fclose(f); 
   return dv; 
}

static void reallocate(DynVec *dv)
{
   dv->n_max *= 2;                                             
   dv->v = (float *)realloc(dv->v, dv->n_max * sizeof(float)); 
}

void dv_insert(DynVec *dv, float x)
{
   if (dv->n == dv->n_max)
      reallocate(dv);
   dv->v[dv->n++] = x; 
}

int dv_size(DynVec *dv)
{
   return dv->n;
}

int dv_capacity(DynVec *dv)
{
   return dv->n_max;
}

float dv_get(DynVec *dv, int i)
{
   assert(i >= 0 && i < dv->n); 
   return dv->v[i];
}

void dv_free(DynVec *dv)
{
   free(dv->v); 
   free(dv);    
}

void dv_print_values(DynVec *dv)
{
   for (int i = 0; i < dv_size(dv); i++) 
      printf("%.2f ", dv_get(dv, i));
   printf("\n");
}

// Implementacao necessaria para auxiliar Union e Intersection
int dv_is_in(DynVec *dv, float x)
{
    for (int i = 0; i < dv->n; i++)
    {
        if (dv->v[i] == x)
            return 1;
    }
    return 0;
}

DynVec *dv_concatenate(DynVec *dv1, DynVec *dv2)
{
   DynVec *dv = dv_create();

   for (int i = 0; i < dv_size(dv1); i++)
      dv_insert(dv, dv_get(dv1, i));

   for (int i = 0; i < dv_size(dv2); i++)
      dv_insert(dv, dv_get(dv2, i));

   return dv;
}

DynVec *dv_union(DynVec *dv1, DynVec *dv2)
{
    DynVec *dv = dv_create();

        for(int i = 0; i < dv_size(dv1); i++) {
        float val = dv_get(dv1, i);
        if(!dv_is_in(dv, val)) {
            dv_insert(dv, val);
        }
    }

        for(int i = 0; i < dv_size(dv2); i++) {
        float val = dv_get(dv2, i);
        if(!dv_is_in(dv, val)) {
            dv_insert(dv, val);
        }
    }

    return dv;
}

DynVec *dv_intersection(DynVec *dv1, DynVec *dv2)
{
    DynVec *dv = dv_create();

    for(int i = 0; i < dv_size(dv1); i++) {
        float val = dv_get(dv1, i);
            if(dv_is_in(dv2, val) && !dv_is_in(dv, val)) {
            dv_insert(dv, val);
        }
    }

    return dv;
}