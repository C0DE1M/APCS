#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string s1, s2, tmp, ans;
bool flag = 1;
int n;
unordered_map <string, int> m;
bool o(int l)
{
    if (l == n)
    {
        return(!m[ans]);
    }
    else
    {
        for(int i = 0; i < s1.size(); i++)
        {
            ans += s1[i];
            if (o(l + 1))
            {
                return 1;
            }
            ans.erase(l);
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> n >> s2;
    for(int i = 0; i <= s2.size() - n; i++)
    {
        m[s2.substr(i, n)]++;
    }
    o(0);
    cout << ans;
}