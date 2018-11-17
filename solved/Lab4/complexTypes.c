#include "complexTypes.h"

short reverse_octets(short no){
    OctetRepresentation oc;
    oc.number = no;
    char aux = oc.octets[0];
    oc.octets[0] = oc.octets[1];
    oc.octets[1] = aux;
    return oc.number;
}
