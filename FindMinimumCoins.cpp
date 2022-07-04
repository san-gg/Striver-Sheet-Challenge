int findMinimumCoins(int amount) {
    int arr[9] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int coins = 0;
    int i = 0;
    while(amount) {
        if(arr[i] <= amount) {
            coins += (amount / arr[i]);
            amount = amount % arr[i];
        }
        ++i;
    }
    return coins;
}
