bool isValid(int (&m)[9][9], int r, int c, int x) {
    for(int i = 0; i < 9; i++) {
        if(m[r][i] == x) return false;
        else if(m[i][c] == x) return false;
        else if(m[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == x)
            return false;
    }
    return true;
}

bool solve(int (&m)[9][9], int r, int c) {
    if(r == 8 && c == 9) return true;
    if(c == 9) {
        r+=1;
        c=0;
    }
    for(int i = r; i < 9; i++) {
        for(int j = c; j < 9; j++) {
            if(m[i][j] == 0) {
                for(int x = 1; x <= 9; x++) {
                    if(isValid(m, i, j, x)) {
                        m[i][j] = x;
                        if(solve(m,r,c+1)) return true;
                        m[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isItSudoku(int (&matrix)[9][9]) {
    return solve(matrix, 0, 0);
}
