#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Movie{
    int id;
    char director[128];
    char actor[128];
    char type[128];
} Movie;
int N;
Movie movies[1000];

int result[1000];
int sum = 0;

void search(char M, char* K) {
    int i;
    int j = 0;
    if (M == 'A') {
        for (i = 0; i < N; i++) {
            if (strcmp(movies[i].actor, K) == 0) {
                result[sum++] = movies[i].id;
            }
        }
    } else if (M == 'D') {
        for (i = 0; i < N; i++) {
            if (strcmp(movies[i].director, K) == 0) {
                result[sum++] = movies[i].id;
            }
        }
    } else if (M == 'T') {
        for (i = 0; i < N; i++) {
            if (strcmp(movies[i].type, K) == 0) {
                result[sum++] = movies[i].id;
            }
        }
    } 
}

int main()
{
    char M;
    char K[128];
    scanf("%d", &N);
    int a = 0;
    
    while (a < N) {
        scanf("%d %s %s %s", &movies[a].id, movies[a].director, movies[a].actor, movies[a].type);
        a++;
    }
    getchar();
    scanf("%c %s", &M, K);
    
    search(M, K);

    if (sum == 0) {
        printf("-1");
        return 0;
    }
    
    for (a = 0; a < sum; a++) {
        printf("%d", result[a]);
        if (a + 1 < sum) {
            printf(" ");
        }
    }
    return 0;
}
