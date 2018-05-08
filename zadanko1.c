#include <stdio.h>

#define pointer(T) typeof(T *)
#define array(T, N) typeof(T [N])
#define mapConstructor(T, N) typeof(array(pointer(T), N))

#define typename(x) _Generic                                                        \
    ((x),                                                                           \
         _Bool: "_Bool",                  unsigned char: "unsigned char",           \
          char: "char",                     signed char: "signed char",             \
     short int: "short int",         unsigned short int: "unsigned short int",      \
           int: "int",                     unsigned int: "unsigned int",            \
      long int: "long int",           unsigned long int: "unsigned long int",       \
 long long int: "long long int", unsigned long long int: "unsigned long long int",  \
         float: "float",                         double: "double",                  \
   long double: "long double",                   char *: "pointer to char",         \
        void *: "pointer to void",                int *: "pointer to int",          \
       default: "other"                                                             \
     )


typedef struct
{
  void (*add)    (void *);
  void (*delete) (void *);
  void (*find)   (void *);
}
assocTable_methods;

typedef struct
{
  assocTable_methods *pointerToMethods;
}
assocTable;

void       _add       (void *incoming);
void       _delete    (void *incoming);
void       _find      (void *incoming);
assocTable _construct (void);

int main (void)
{
  mapConstructor(char, 4) c;
  printf("type of b is %s\n", typename(b));

  return 0;
}

assocTable _construct(void)
{
  assocTable Map;
  Map.pointerToMethods->add    = _add;
  Map.pointerToMethods->delete = _delete;
  Map.pointerToMethods->find   = _find;

  return Map;
}

void _add(void *incoming)
{
  printf("_add()");
}

void _delete(void *incoming)
{
  printf("_delete");
}

void _find(void *incoming)
{
  printf("_find");
}
