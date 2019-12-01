//DFS
int g_row, g_col;

void dfs(char** grid, int row, int col){
    //若遍历过则置为0因此也不需要存储已遍历过
    grid[row][col] = 0;
    //有一个就近原则，两者顺序不能相反
    if((row+1)<g_row&&grid[row+1][col]=='1'){
        dfs(grid, row + 1, col);
    }
    if((row-1)>=0&&grid[row-1][col]=='1'){
        dfs(grid, row - 1, col);
    }
    if((col+1)<g_col&&grid[row][col+1]=='1'){
        dfs(grid, row, col + 1);
    }
    if((col-1)>=0&&grid[row][col-1]=='1'){
        dfs(grid, row, col - 1);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(gridSize<=0){
        return 0;
    }
    g_row = gridSize;
    g_col = *gridColSize;
    int i, j;
    int islandNum = 0;
    for (i = 0; i < g_row;i++){
        for (j = 0; j < g_col;j++){
            if(grid[i][j]=='1'){
                islandNum++;
                dfs(grid, i, j);
            }
        }
    }
    return islandNum;
}