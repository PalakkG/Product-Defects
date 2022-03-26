#include <bits/stdc++.h>

using namespace std;

void largestDefectiveSquare(vector<vector<bool>> &samples)
{
    int res = 0;
    int rows = samples.size();

    // exits the function if no. of rows is zero
    if (!rows)
    {
        return;
    }

    int cols = samples[0].size();

    // declares a 2D vector of the same order as samples matrix
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // creates a copy of samples with integer type elements for manipulation
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = samples[i][j] - 0;
            res = max(res, matrix[i][j]);
        }
    }

    /*
        matrix vector
        1 1 1 1 1
        1 1 1 0 0
        1 1 1 0 0
        1 1 1 0 0
        1 1 1 1 1
    */

    // computes the maximum square of 1s by comparing adjacent elements
    for (int i = rows - 2; i >= 0; i--)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j])
            {
                matrix[i][j] = 1 + min({matrix[i + 1][j], matrix[i][j - 1], matrix[i + 1][j - 1]});
            }
            res = max(res, matrix[i][j]);
        }
    }

    /*
        matrix vector after manipulation
        1 2 3 1 1
        1 2 3 0 0
        1 2 3 0 0
        1 2 2 0 0
        1 1 1 1 1
    */

    cout << res << endl;
}

int main()
{

    auto startTime  = std::chrono::high_resolution_clock::now(); 


    int rows, cols;
    vector<vector<bool>> samples;

    // takes in the required size of matrix
    cin >> rows >> cols;

    // takes in the elements for the 2D matrix
    for (int i = 0; i < rows; i++)
    {
        vector<bool> temp;
        for (int j = 0; j < cols; j++)
        {
            bool elem;
            cin >> elem;
            temp.push_back(elem);
        }
        samples.push_back(temp);
    }

    /*
        samples vector
        1 1 1 1 1
        1 1 1 0 0
        1 1 1 0 0
        1 1 1 0 0
        1 1 1 1 1
    */

    largestDefectiveSquare(samples);
    
    auto endTime = std::chrono::high_resolution_clock::now(); 

    std::chrono::duration<double> elapsed = endTime - startTime;

    // prints the time taken for execution
    cout << elapsed.count();
    
    return 0;
}
