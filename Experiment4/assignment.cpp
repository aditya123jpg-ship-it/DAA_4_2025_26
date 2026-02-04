#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int K, N;
    cin >> K >> N;

    priority_queue<int, vector<int>, greater<int>> mh;

    for(int i = 0; i < N; i++)
    {
        int sc;
        cin >> sc;

        if(mh.size() < K)
        {
            mh.push(sc);

            if(mh.size() < K)
                cout << -1 << endl;
            else
                cout << mh.top() << endl;
        }
        else
        {
            if(sc > mh.top())
            {
                mh.pop();
                mh.push(sc);
            }
            cout << mh.top() << endl;
        }
    }

    return 0;
}
