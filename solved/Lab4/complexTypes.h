#ifndef COMPLEXTYPES_H_INCLUDED
#define COMPLEXTYPES_H_INCLUDED

typedef union OctetRepresentation {
    char octets[2];
    short number;
} OctetRepresentation;

typedef struct Locuinta {
    char adresa[101];
    float suprafata;
    char tip[31];
    short camere;
    union {
        unsigned short balcon;
        char decomandat;
        char info[16];
    } specific;
} Locuinta;


typedef struct Angajat {
    unsigned short varsta : 6;
    unsigned short norma : 1;
    char nume[30];
    long long cnp;
} Angajat;

typedef struct Dosar {
    unsigned char copieBuletin : 1;
    unsigned char copieCertificatCasatorie : 1;
    unsigned char copieDiplomaLicenta : 1;
    unsigned char copieDiplomaMaster : 1;
    unsigned char copieDiplomaDoctor : 1;
    unsigned char fisaLichidare : 1;
    unsigned char certificatNastereCopii : 1;
} Dosar;


short reverse_octets(short);

#endif // COMPLEXTYPES_H_INCLUDED
