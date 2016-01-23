


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

    int size;
    scanf("%d", &size);

    char *a = malloc(size * sizeof(char));

    for (int i = 0; i < size; i++) {

        signed char p;
        scanf("%c", &p);

        a[i] = p;

    }


    return 0;
}
