typedef vector<vector<int>> vvi;

void recurse(vvi &image, int &oldColor, int x, int y, int newColor) {
    int m = image.size();
    int n = image[0].size();
    if(x == -1 || y == -1 || x == m || y == n) return;
    if(image[x][y] != oldColor) return;
    //upward
    image[x][y] = oldColor;
    if(x >= 0 && image[x][y] == oldColor) {
        image[x][y] = newColor;
        recurse(image, oldColor, x-1, y, newColor);
    }
    //left
    image[x][y] = oldColor;
    if(y >= 0 && image[x][y] == oldColor) {
        image[x][y] = newColor;
        recurse(image, oldColor, x, y-1, newColor);
    }
    //right
    image[x][y] = oldColor;
    if(y < n && image[x][y] == oldColor) {
        image[x][y] = newColor;
        recurse(image, oldColor, x, y+1, newColor);
    }
    //down
    image[x][y] = oldColor;
    if(x < m && image[x][y] == oldColor) {
        image[x][y] = newColor;
        recurse(image, oldColor, x+1, y, newColor);
    }
    return;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int oldColor = image[x][y];
    if(oldColor != newColor)
        recurse(image, oldColor, x, y, newColor);
    return image;
}