#include <iostream>
using namespace std;

int main()
{
    int n, n_h, p_h = 0, now = 0, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &n_h);
        if (n_h < p_h)
        {
            now++;
        }
        else
        {
            ans = max(ans, now);
            now = 1;
        }
        p_h = n_h;
    }
    ans = max(ans, now);
    printf("%d", ans);
}