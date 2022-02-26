#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>


int main() {
    char sir[256];
    scanf("%[^\n]s", sir);
    char *p;
    p = strtok(sir, " ");
    char listaCuvinte[100][256];
    int nrCuv = 0;

    while (p!=NULL) {
        strcpy(listaCuvinte[nrCuv++], p);
        p = strtok(NULL, " ");
    }
    
    int ok;
    do {
        ok = 0;
        for (int i=0;i<nrCuv-1;i++) {
            int l1 = strlen(listaCuvinte[i]);
            int l2 = strlen(listaCuvinte[i + 1]);
            if (l2>l1) {
                char aux[256];
                strcpy(aux, listaCuvinte[i]);
                strcpy(listaCuvinte[i], listaCuvinte[i + 1]);
                strcpy(listaCuvinte[i + 1], aux);
                ok = 1;
            }
            if (l2==l1) {
                if (strcmp(listaCuvinte[i],listaCuvinte[i+1])>0) {
                    char aux[256];
                    strcpy(aux, listaCuvinte[i]);
                    strcpy(listaCuvinte[i], listaCuvinte[i + 1]);
                    strcpy(listaCuvinte[i + 1], aux);
                    ok = 1;
                }
            }
        }
    } while (ok);
    for (int i = 0; i < nrCuv; i++)
        printf("%s \n", listaCuvinte[i]);
    return 0;
}