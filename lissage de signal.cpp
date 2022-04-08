#include <iostream>
#include <cmath>
using namespace std;

bool lissage(float* x, float* z, float diffMax, int  nbMesures) {
    int i = 0;
    bool lissag = true;
    while (i < nbMesures - 1) {
        if (abs(x[i] - x[i + 1]) > diffMax) {
            lissag = false;
            if (i != 0) {
                z[i] = (x[i - 1] + x[i + 1]) / 2;
            }
        }
        if (i != 0) {
            z[i] = (x[i - 1] + x[i + 1]) / 2;
        }

        i++;
    }

    return lissag;
}
int  main()
{
    int nbMesures;
    float  diffMax;


    cin >> nbMesures;
    cin >> diffMax;
    float* x = new float[nbMesures];
    float* z = new float[nbMesures];
    int i;
    for (i = 0; i < nbMesures; i++) {
        cin >> x[i];
    }
    int passage = 0;
    /*if (lissage(x, z, diffMax, nbMesures) == false) {
        cout << "false";
    }
    else {
        cout << "true";
    }*/
    while (lissage(x, z, diffMax, nbMesures) == false) {
        int j;
        for (j = 1; j < nbMesures - 1; j++) {
            x[j] = z[j];
        }
        passage++;

    }



    delete[]x;
    delete[]z;
    cout << passage;



    return 0;
}