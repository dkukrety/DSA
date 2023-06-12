#include <iostream>
#include <vector>

using namespace std;

/*
Given some balls of three colors arranged in a line, rearrange them such that all the red balls go first, then green and then blue ones.

Do rearrange the balls in place. A solution that simply counts colors and overwrites the array is not the one we are looking for.

This is an important problem in search algorithms theory proposed by Dutch computer scientist Edsger Dijkstra. Dutch national flag has three colors (albeit different from ones used in this problem).

Example
{
"balls": ["G", "B", "G", "G", "R", "B", "R", "G"]
}
["G", "G", "G", "G", "R", "B", "R", "B"]
["R", "G", "G", "G", "G", "B", "R", "B"]
["R", "G", "G", "G", "G", "R", "B", "B"]
r=0
b=7

b=6,
r=1
b=5

Output:

["R", "R", "G", "G", "G", "G", "B", "B"]

Logic is to have two pointers, one will track R to be put in left most side of array
another is to track B and to be put on right most part of array
for G we will just move ahead.

Another way to solve this is to use counting array, but that will take extra space.

Below is o(n) time complexity and o(1) space complexity.

*/

int main()
{
    vector<char> balls = {'R', 'R', 'R', 'R', 'R', 'B', 'R', 'B'};
    int rIndex = 0;
    int bIndex = balls.size() - 1;

    for (int i = 0; i < balls.size(); i++)
    {
        // cout << balls[i] << "   ";
        if (balls[i] == 'G')
            continue;
        else if (balls[i] == 'R' && rIndex <= i)
        {
            cout << balls[i] << "   " << i << "  " << balls[rIndex] << " at " << rIndex << endl;
            swap(balls[i], balls[rIndex]);
            // decrementing i so that balls[i] can be re-processed again as swapping has happened.
            i--;
            rIndex++;
        }
        else if (balls[i] == 'B' && bIndex > i)
        {
            // cout << balls[i] << "   " << i << "  " << balls[bIndex] << " at " << bIndex << endl;
            swap(balls[i], balls[bIndex]);
            // decrementing i so that balls[i] can be re-processed again as swapping has happened.
            i--;
            // cout << balls[i] << "   " << i << "  " << balls[bIndex] << "  ";
            bIndex--;
        }
    }

    for (auto &i : balls)
    {
        cout << i << " ";
    }
    return 0;
}