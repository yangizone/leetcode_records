int maxProfit(int* prices, int pricesSize){
    //即求最大子序和问题
    int minPrice = INT_MAX;
    int maxProfit = 0;
    int i;
    for (i = 0; i < pricesSize;i++){
        if(prices[i]<minPrice){
            minPrice = prices[i];
        }
        else if(prices[i]-minPrice>maxProfit){
            maxProfit = prices[i] - minPrice;
        }
        else{
            ;
        }
    }
    return maxProfit;
}