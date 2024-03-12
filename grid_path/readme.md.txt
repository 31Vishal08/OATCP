The given C++ solution addresses the problem of finding the number of paths in a maze from the top-left to the bottom-right cell, considering only right and down movements while avoiding blocked cells. The algorithm initializes a boolean grid to represent the maze and utilizes dynamic programming to calculate the number of paths for each cell. It iterates through the grid from the bottom-right towards the top-left, considering possible movements and updating the dynamic programming array accordingly. The final result is outputted, representing the count of paths from the top-left to the bottom-right cell, accounting for blocked cells in the maze. The provided pseudocode and comments in the code offer a clear understanding of the step-by-step approach used to solve the problem.

PSUEDOCODE:

// Input Reading
Read n

// Grid Initialization
Create grid[n+1][n+1]
For i = 1 to n
    For j = 1 to n
        Read ch
        If ch is '.'
            Set grid[i][j] = 0 (empty cell)
        Else
            Set grid[i][j] = 1 (blocked cell)

// Dynamic Programming
Create dp[n+1][n+1]
For i = n to 1
    For j = n to 1
        If i == n and j == n
            Set dp[i][j] = 1
        Else
            Set op1 = (j == n) ? 0 : dp[i][j+1]
            Set op2 = (i == n) ? 0 : dp[i+1][j]
            Set dp[i][j] = (op1 + op2) % mod
            If grid[i][j] is blocked
                Set dp[i][j] = 0

// Output
If the top-left cell is blocked (grid[1][1] == 1)
    Output 0
Else
    Output dp[1][1]
