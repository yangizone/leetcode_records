int dp(int** obstacleGrid, int **result, int x, int y, int col,int row){
    if (x >= col || y>=row){
        return 0;
    }
    if(result[x][y]!=-1){
        return result[x][y];
    }
    //用例有一个终点放障碍，只能放前面了
    if(obstacleGrid[x][y]==1){
        result[x][y] = 0;
        return result[x][y];
    }
    if(x==col-1 && y==row-1){
        result[x][y] = 1;
        return result[x][y];
    }
    int downWays = dp(obstacleGrid, result, x + 1, y, col, row);
    int rightWays = dp(obstacleGrid, result, x, y + 1, col, row);
    result[x][y] = downWays + rightWays;
    return result[x][y];
}
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int **result = (int **)malloc(sizeof(int *) * obstacleGridSize);
    int i;
    for (i = 0; i < obstacleGridSize;i++){
        result[i] = (int *)malloc(sizeof(int) * *obstacleGridColSize);
    }
    for (i = 0; i < obstacleGridSize;i++){
        memset(result[i], -1, sizeof(int) * *obstacleGridColSize);
    }
    int ways = dp(obstacleGrid, result, 0, 0, obstacleGridSize, *obstacleGridColSize);
    for (i = 0; i < obstacleGridSize;i++){
        free(result[i]);
    }
    free(result);
    return ways;
}