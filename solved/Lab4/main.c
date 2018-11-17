#include <stdio.h>
#include "complexTypes.h"

int main()
{

    
    short no = 20;
    short encoded = reverse_octets(no);
    printf("%d codificat este %d\n", no, encoded);
    printf("%d decoficat este %d\n", encoded, reverse_octets(encoded));

    printf("%u",sizeof(Dosar));
    


    return 0;
}
