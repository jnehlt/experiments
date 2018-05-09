#include <stdio.h>
#include <stdlib.h>

#define pointer(T) typeof(T *)
#define array(T, N) typeof(T [N])
//#define mapConstructor(T, N) typeof(array(pointer(T), N))

#define Map(T, N)                           \
({  typeof(T) _T = 0;                       \
    typeof(N) _N = 0;                       \
    _construct(typename(_N), typename(_T)); \
})

#define typename(x) _Generic                    \
    ((x),                                       \
         _Bool: 1,           unsigned char: 2,  \
          char: 3,             signed char: 4,  \
     short int: 5,      unsigned short int: 6,  \
           int: 7,            unsigned int: 8,  \
      long int: 9,       unsigned long int: 10, \
 long long int: 11, unsigned long long int: 12, \
         float: 13,                 double: 14, \
   long double: 15,                default: -1  \
     )

struct assocTable_methods
{
  void (*add)    (void *, int);
  void (*delete) (void *, int);
  void (*find)   (void *, int);
};

typedef struct
{
  int size;
  int keyType;
  int valueType;
}
assocTable_values;

typedef struct
{
  const struct assocTable_methods *pointerToMethods;
  assocTable_values               *pointerToValues;
}
assocTable;

void       _add       (void *incoming, int type);
void       _delete    (void *incoming, int type);
void       _find      (void *incoming, int type);
assocTable _construct (int  keyType,   int valueType);

static const struct assocTable_methods
  assocTable_static_methods =
  {
    _add,
    _delete,
    _find
  };

int main (void)
{
  assocTable mapa = Map(char, int);
  printf("mapa.pointerToValues = %p\n"    , mapa.pointerToValues);
  printf("mapa.pointerToValues->size = %d", mapa.pointerToValues->size);

  return 0;
}

assocTable _construct(int keyType, int valueType)
{
  assocTable Map;

  Map.pointerToMethods = &assocTable_static_methods;
  Map.pointerToValues  = (assocTable_values  *)malloc(sizeof(assocTable_values ));

  Map.pointerToValues->size      = 0;
  Map.pointerToValues->keyType   = keyType;
  Map.pointerToValues->valueType = valueType;

  return Map;
}

void _add(void *incoming, int type)
{
  printf("_add()");
}

void _delete(void *incoming, int type)
{
  printf("_delete");
}

void _find(void *incoming, int type)
{
  printf("_find");
}
