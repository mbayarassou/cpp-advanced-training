#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <deque>

using namespace std;

int main()
{
    cout << "Create vector vNumbers " << endl;

    vector<int> vNumbers  {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    auto it = vNumbers.begin();
    auto nx = ;
    cout << "vNumbers[3]=" << *nx << '\n';
 
    it = vNumbers.end();
    nx = ;
    cout << "vNumbers[7]=" << *nx << '\n';
 
    it = vNumbers.begin();
    auto pr = ;
    cout << "vNumbers[4]=" << *pr << '\n';
 
    it = vNumbers.end();
    pr = ;
    cout << "vNumbers[8]=" << *pr << '\n';

    return 0;
}