/*

One pixel on a grayscale image changes color. Recolor all the adjacent pixels of the same color to the same new color.

Grayscale colors are simply numbers.

Example One
{
"pixel_row": 0,
"pixel_column": 1,
"new_color": 2,
"image": [
[0, 1, 3],
[1, 1, 1],
[1, 5, 4]
]
}
I.e. the pixel at row 0 and column 1 changes to color 2.

Output:

[
[0, 2, 3],
[2, 2, 2],
[2, 5, 4]
]
Example Two
{
"pixel_row": 1,
"pixel_column": 0,
"new_color": 9,
"image": [
[0, 2, 1],
[1, 1, 2],
[2, 5, 4]
]
}
I.e. the pixel at row 1 and column 0 changes to color 9.

Output:

[
[0, 2, 1],
[9, 9, 2],
[2, 5, 4]
]
Notes
Two pixels are considered adjacent if they share a side; sharing a diagonal is not enough.

Constraints:

1 <= image width <= 1000
1 <= image height <= 1000
0 <= pixel color <= 1000

*/
const int add_r[4] = {0, -1, 0, 1};
const int add_c[4] = {-1, 0, 1, 0};

void getNeibours(pair<int, int> temp, vector<vector<int>> &image, int rowLen, int colLen, int current_color, int new_color, queue<pair<int, int>> &q)
{
    // cout<<"getNeibours  "<<"rowLen="<<rowLen<<"colLen="<<colLen<<endl;
    for (int i = 0; i < 4; i++)
    {
        // Try to visit all 4 neighbours.
        int new_row = temp.first + add_r[i];
        int new_column = temp.second + add_c[i];

        // Out of the matrix.
        // cout<<"getNeibours before check  "<<"rowLen="<<rowLen<<"colLen="<<colLen<<endl;
        // cout<<"getNeibours before "<<"new_row="<<new_row<<"new_column="<<new_column<<endl;
        if (new_row < 0 || new_row >= rowLen || new_column < 0 || new_column >= colLen)
        {
            continue;
        }

        if (image[new_row][new_column] == current_color)
        {
            q.push(make_pair(new_row, new_column));
            image[new_row][new_column] = new_color;
        }
    }
}

void dfs(int row, int col, int current_color, int new_color, vector<vector<int>> &image, int rowLen, int colLen)
{
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    image[row][col] = new_color;

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        cout << row << "  " << col;

        // vector<pair<int,int>> pairList;
        getNeibours(temp, image, rowLen, colLen, current_color, new_color, q);
    }
}

vector<vector<int>> flood_fill(int pixel_row, int pixel_column, int new_color, vector<vector<int>> &image)
{
    // Write your code here.
    int current_color = image[pixel_row][pixel_column];
    if (current_color == new_color)
        return image;

    int n = image.size();
    int m = image[0].size();

    dfs(pixel_row, pixel_column, current_color, new_color, image, n, m);

    return image;
}
