/*
 * Gera polinômios aleatórios para o EP2:
 *
 * $ ./random_poly 5 31415
 *   0 -0.245865390170
 *   1  0.341196756810
 *   2  0.882763302885
 *   3  0.906618377659
 *   4  0.096589357127
 *   5  0.717764343601
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int d = atoi(argv[1]), seed = atoi(argv[2]);

    srand(seed);
    for (int i = 0; i <= d; ++i) {
        double c = rand() / (RAND_MAX + 1.0);
        printf("%3d %15.12lf\n", i, c * (rand() % 2 == 0 ? 1 : -1));
    }

    return 0;
}
