class Solution {

    private char[][] rotateClockwise(char[][] box) {
        int m = box.length, n = box[0].length;
        char[][] result = new char[n][m];
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                result[j][i] = box[i][j];
            }
        }

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m/2; j++) {
                char t = result[i][j];
                result[i][j] = result[i][m - j - 1];
                result[i][m-j-1] = t;
            }
        }
        return result;
    }

    public char[][] rotateTheBox(char[][] boxGrid) {
        char[][] result = rotateClockwise(boxGrid);
        int m = result.length, n = result[0].length;
        for(int j = 0; j<n; j++) {
            int ground = m-1, idx = m-1;
            while(ground >= 0 && result[ground][j] != '.') {
                ground--;
            }
            idx = ground;
            while (idx >= 0) {
                if (idx >= ground) {
                    idx = ground-1;
                    continue;
                }
                if (result[idx][j] == '#') {
                    result[ground][j] = '#';
                    result[idx][j] = '.';
                }
                else if (result[idx][j] == '*') {
                    ground = idx-1;
                }
                while(ground > 0 && result[ground][j] != '.'){
                    ground--;
                }
                idx--;
            }
        }

        return result;
    }
}