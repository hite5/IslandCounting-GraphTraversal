#include <iostream>
#include <vector>
#include <array>
#include <queue>


using namespace std;


// Breadth first search approach
void BFS(vector<vector<int>> grid, vector<vector<int>> &visited, int row, int col, int n)
{
    queue<int> search;
    search.push(row);
    search.push(col);
    do
    {
        row = search.front();
        search.pop();
        col = search.front();
        search.pop();
        // check the cell to below
        if (row != n-1 && grid[row + 1][col] == 1 && visited[row+1][col] == 0)
        {
            search.push(row + 1);
            search.push(col);
        }
        
        // check the cell to the right
        if (col != n-1 && grid[row][col + 1] == 1 && visited[row][col+1] == 0)
        {
            search.push(row);
            search.push(col + 1);
        }
        
        // check the cell above
        if (row != 0 && grid[row - 1][col] == 1 && visited[row-1][col] == 0)
        {
            search.push(row - 1);
            search.push(col);
        }
        
        // check the cell to the left
        if (col != 0 && grid[row][col - 1] == 1 && visited[row][col-1] == 0)
        {
            search.push(row);
            search.push(col - 1);
        }
        visited[row][col] = 1;
    } while (!search.empty());
}

int main()
{
    int n;
    cin >> n ;

    vector<vector<int>> grid(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    vector<vector<int>> visited(n, vector<int>(n));
    

    // now count how many islands!
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 1 && visited[i][j] == 0){
                BFS(grid, visited, i, j, n);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
