//
//  main.cpp
//  assignment05
//
//  Created by Tucker King on 10/5/21.
//

#include <iostream>

using namespace std;

void recursive_tower_of_hanoi(int n, char start, char end, char aux)
{
    if(n== 1)
    {
        cout << "Move disk 1 from rod " << start << " to rod " << end << endl;
        return;
    }
    
    recursive_tower_of_hanoi(n-1, start, aux, end);
    cout << "Move disk " << n << " from rod " << start << " to rod " << end << endl;
    recursive_tower_of_hanoi(n-1, aux, end, start);
}

int main(int argc, const char * argv[])
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    cout << endl;
    
    recursive_tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}
