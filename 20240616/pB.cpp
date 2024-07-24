#include <iostream>
#include <cstring>
using namespace std;


int h, w, n, r, c, t, color;
int map[20][20];

int main()
{
    int tmp;
    memset(map, 0, sizeof(map));
    scanf("%d %d %d", &h, &w, &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &r, &c, &t, &color);
        for(int j = 0; j < h; j++)
        {
            for(int k = 0; k < w; k++)
            {
                if (abs(j - r) + abs(k - c) <= t)
                {
                    map[j][k] += color;
                }
            }
        }
    }
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}