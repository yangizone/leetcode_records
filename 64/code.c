#define getMin(x,y) ((x<y)?x:y)
int dp(int** grid, int** distances,int x, int y, int col, int row){
    //考虑到边界处理不想特殊处理
    //因此选择返回最大值和对最右下角进行特殊判断
    if(x>=col || y>=row){
        return INT_MAX;
    }
    if(distances[x][y]!=0){
        return distances[x][y];
    }
    if(x==col-1 && y==row-1){
        distances[x][y] = grid[x][y];
        return distances[x][y];
    }
    int down = dp(grid, distances, x + 1, y, col, row);
    int right = dp(grid, distances, x, y + 1, col, row);
    distances[x][y] = getMin(down, right) + grid[x][y];
    return distances[x][y];
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    //考虑为0的情况
    if(gridSize==0){
        return 0;
    }
    int **distances=(int **)malloc(sizeof(int *)*gridSize);
    int i;
    for (i = 0; i < gridSize;i++){
        distances[i] = (int *)malloc(sizeof(int) * *gridColSize);
    }
    for (i = 0; i < gridSize;i++){
        memset(distances[i], 0, sizeof(int) * *gridColSize);
    }
    int distance = dp(grid, distances, 0, 0, gridSize, *gridColSize);
    // int j;
    // for (i = 0; i < gridSize;i++){
    //     for (j = 0; j < *gridColSize;j++){
    //         printf("%d ", distances[i][j]);
    //     }
    //     printf("\n");
    // }
    for (i = 0; i < gridSize;i++){
        free(distances[i]);
    }
    free(distances);
    return distance;
}