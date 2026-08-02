#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        cout << "Move Disk 1 from "
             << source << " to " << destination << endl;
        return;
    }

    TowerOfHanoi(n - 1, source, destination, auxiliary);

    cout << "Move Disk " << n
         << " from " << source
         << " to " << destination << endl;

    TowerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n = 3;

    TowerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
