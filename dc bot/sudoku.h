#include <bits/stdc++.h>
using namespace std;

int x = 0, y = 0, sta = 1;

class Sudoku {

public:
    //  declear 2D array pointer
    int** res;
    int** mat;
    int** ans;

    int N, K, aht, bc, c;

    struct move {
        int ix;
        int jy;
        int in;
    };

    stack<move> mbw;  //  move backward
    stack<move> mfw;  //  move foreward

    time_t clk = time(0);  //  record the time

    bool ise;  //  if sudoku end

    //  construct a cool ending output
    string cgl[9] = {
"                                         __      __      __  _             __\n\
  _________  ____  ____ __________ _____/ /_  __/ /___ _/ /_(_)___  ____  / /\n\
 / ___/ __ \\/ __ \\/ __ `/ ___/ __ `/ __  / / / / / __ `/ __/ / __ \\/ __ \\/ / \n\
/ /__/ /_/ / / / / /_/ / /  / /_/ / /_/ / /_/ / / /_/ / /_/ / /_/ / / / /_/  \n\
\\___/\\____/_/ /_/\\__, /_/   \\__,_/\\__,_/\\__,_/_/\\__,_/\\__/_/\\____/_/ /_(_)   \n\
                /____/                                                       \n\
",  //  an ascii art
"\
                                                                                            ###\n\
 ####   ####  #    #  ####  #####    ##   #####  #    # #        ##   ##### #  ####  #    # ###\n\
#    # #    # ##   # #    # #    #  #  #  #    # #    # #       #  #    #   # #    # ##   # ###\n\
#      #    # # #  # #      #    # #    # #    # #    # #      #    #   #   # #    # # #  #  # \n\
#      #    # #  # # #  ### #####  ###### #    # #    # #      ######   #   # #    # #  # #    \n\
#    # #    # #   ## #    # #   #  #    # #    # #    # #      #    #   #   # #    # #   ## ###\n\
 ####   ####  #    #  ####  #    # #    # #####   ####  ###### #    #   #   #  ####  #    # ###\n\
",  //  an ascii art
"\n\
                                                            dP          dP            dP   oo                   dP\n\
                                                            88          88            88                        88\n\
.d8888b. .d8888b. 88d888b. .d8888b. 88d888b. .d8888b. .d888b88 dP    dP 88 .d8888b. d8888P dP .d8888b. 88d888b. 88\n\
88'  `\"\" 88'  `88 88'  `88 88'  `88 88'  `88 88'  `88 88'  `88 88    88 88 88'  `88   88   88 88'  `88 88'  `88 dP\n\
88.  ... 88.  .88 88    88 88.  .88 88       88.  .88 88.  .88 88.  .88 88 88.  .88   88   88 88.  .88 88    88\n\
`88888P' `88888P' dP    dP `8888P88 dP       `88888P8 `88888P8 `88888P' dP `88888P8   dP   dP `88888P' dP    dP oo\n\
                                .88\n\
                            d8888P\n\
",  //  an ascii art
"\
                                            o         o                              oO\n\
                                           O         O               o               OO\n\
                                           o         o           O                   oO\n\
                                           o         O          oOo                  Oo\n\
.oOo. .oOo. 'OoOo. .oOoO `OoOo. .oOoO' .oOoO  O   o  o  .oOoO'   o   O  .oOo. 'OoOo. oO\n\
O     O   o  o   O o   O  o     O   o  o   O  o   O  O  O   o    O   o  O   o  o   O   \n\
o     o   O  O   o O   o  O     o   O  O   o  O   o  o  o   O    o   O  o   O  O   o Oo\n\
`OoO' `OoO'  o   O `OoOo  o     `OoO'o `OoO'o `OoO'o Oo `OoO'o   `oO o' `OoO'  o   O oO\n\
                       O                                                               \n\
                    OoO'                                                               \n\
",  //  an ascii art
"\
                                          _________      ______      __________              ______ \n\
__________________________ _____________ ______  / ___  ____ / _____ __ /___(_)_______________  /  \n\
_  ___ / __ \\_  __ \\_  __ `/_  ___ / __ `/  __  /_  / / /_  / _  __ `/ __/_  /_  __ \\_  __ \\_  /\n\
/ /__ / /_/ /  / / /  /_/ /_  /   / /_/ // /_/ / / /_/ /_  / / /_/ // /_ _  / / /_/ /  / / //_/  \n\
\\___ /\\____//_/ /_/_\\__, / /_/    \\__,_/ \\__,_/  \\__,_/ /_/  \\__,_/ \\__/ /_/  \\____//_/ /_/(_)   \n\
                 / ____ /                                                                       \n\
",  //  an ascii art
"\
 ¢i¢i¢i¢i¢i¢iùß ¢i¢i¢i¢i¢i¢iùß ¢i¢i¢iùß   ¢i¢iùß ¢i¢i¢i¢i¢i¢iùß ¢i¢i¢i¢i¢i¢iùß  ¢i¢i¢i¢i¢iùß ¢i¢i¢i¢i¢i¢iùß ¢i¢iùß   ¢i¢iùß¢i¢iùß      ¢i¢i¢i¢i¢iùß ¢i¢i¢i¢i¢i¢i¢i¢iùß¢i¢iùß ¢i¢i¢i¢i¢i¢iùß ¢i¢i¢iùß   ¢i¢iùß¢i¢iùß\n\
¢i¢iùÝùùùùùùùùùå¢i¢iùÝùùùùùù¢i¢iùß¢i¢i¢i¢iùß  ¢i¢iùø¢i¢iùÝùùùùùùùùùå ¢i¢iùÝùùùù¢i¢iùß¢i¢iùÝùùùù¢i¢iùß¢i¢iùÝùùùù¢i¢iùß¢i¢iùø   ¢i¢iùø¢i¢iùø     ¢i¢iùÝùùùù¢i¢iùßùãùùùù¢i¢iùÝùùùùùå¢i¢iùø¢i¢iùÝùùùùùù¢i¢iùß¢i¢i¢i¢iùß  ¢i¢iùø¢i¢iùø\n\
¢i¢iùø     ¢i¢iùø   ¢i¢iùø¢i¢iùÝ¢i¢iùß ¢i¢iùø¢i¢iùø  ¢i¢i¢iùß¢i¢i¢i¢i¢i¢iùÝùå¢i¢i¢i¢i¢i¢i¢iùø¢i¢iùø  ¢i¢iùø¢i¢iùø   ¢i¢iùø¢i¢iùø     ¢i¢i¢i¢i¢i¢i¢iùø   ¢i¢iùø   ¢i¢iùø¢i¢iùø   ¢i¢iùø¢i¢iùÝ¢i¢iùß ¢i¢iùø¢i¢iùø\n\
¢i¢iùø     ¢i¢iùø   ¢i¢iùø¢i¢iùøùã¢i¢iùß¢i¢iùø¢i¢iùø   ¢i¢iùø¢i¢iùÝùùùù¢i¢iùß¢i¢iùÝùùùù¢i¢iùø¢i¢iùø  ¢i¢iùø¢i¢iùø   ¢i¢iùø¢i¢iùø     ¢i¢iùÝùùùù¢i¢iùø   ¢i¢iùø   ¢i¢iùø¢i¢iùø   ¢i¢iùø¢i¢iùøùã¢i¢iùß¢i¢iùøùãùùùå\n\
ùã¢i¢i¢i¢i¢i¢iùßùã¢i¢i¢i¢i¢i¢iùÝùå¢i¢iùø ùã¢i¢i¢i¢iùøùã¢i¢i¢i¢i¢i¢iùÝùå¢i¢iùø  ¢i¢iùø¢i¢iùø  ¢i¢iùø¢i¢i¢i¢i¢i¢iùÝùåùã¢i¢i¢i¢i¢i¢iùÝùå¢i¢i¢i¢i¢i¢i¢iùß¢i¢iùø  ¢i¢iùø   ¢i¢iùø   ¢i¢iùøùã¢i¢i¢i¢i¢i¢iùÝùå¢i¢iùø ùã¢i¢i¢i¢iùø¢i¢iùß\n\
 ùãùùùùùùùùùùùå ùãùùùùùùùùùùùå ùãùùùå  ùãùùùùùùùå ùãùùùùùùùùùùùå ùãùùùå  ùãùùùåùãùùùå  ùãùùùåùãùùùùùùùùùùùå  ùãùùùùùùùùùùùå ùãùùùùùùùùùùùùùåùãùùùå  ùãùùùå   ùãùùùå   ùãùùùå ùãùùùùùùùùùùùå ùãùùùå  ùãùùùùùùùåùãùùùå\n\
",  //  an ascii art
"\
 ¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i  ¢i¢i¢i    ¢i¢i  ¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i   ¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i  ¢i¢i    ¢i¢i ¢i¢i       ¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i¢i ¢i¢i  ¢i¢i¢i¢i¢i¢i  ¢i¢i¢i    ¢i¢i ¢i¢i\n\
¢i¢i      ¢i¢i    ¢i¢i ¢i¢i¢i¢i   ¢i¢i ¢i¢i       ¢i¢i   ¢i¢i ¢i¢i   ¢i¢i ¢i¢i   ¢i¢i ¢i¢i    ¢i¢i ¢i¢i      ¢i¢i   ¢i¢i    ¢i¢i    ¢i¢i ¢i¢i    ¢i¢i ¢i¢i¢i¢i   ¢i¢i ¢i¢i\n\
¢i¢i      ¢i¢i    ¢i¢i ¢i¢i ¢i¢i  ¢i¢i ¢i¢i   ¢i¢i¢i ¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i ¢i¢i   ¢i¢i ¢i¢i    ¢i¢i ¢i¢i      ¢i¢i¢i¢i¢i¢i¢i    ¢i¢i    ¢i¢i ¢i¢i    ¢i¢i ¢i¢i ¢i¢i  ¢i¢i ¢i¢i\n\
¢i¢i      ¢i¢i    ¢i¢i ¢i¢i  ¢i¢i ¢i¢i ¢i¢i    ¢i¢i ¢i¢i   ¢i¢i ¢i¢i   ¢i¢i ¢i¢i   ¢i¢i ¢i¢i    ¢i¢i ¢i¢i      ¢i¢i   ¢i¢i    ¢i¢i    ¢i¢i ¢i¢i    ¢i¢i ¢i¢i  ¢i¢i ¢i¢i   \n\
 ¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i  ¢i¢i   ¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i  ¢i¢i   ¢i¢i ¢i¢i   ¢i¢i ¢i¢i¢i¢i¢i¢i   ¢i¢i¢i¢i¢i¢i  ¢i¢i¢i¢i¢i¢i¢i ¢i¢i   ¢i¢i    ¢i¢i    ¢i¢i  ¢i¢i¢i¢i¢i¢i  ¢i¢i   ¢i¢i¢i¢i ¢i¢i\n\
",  //  an ascii art
"\
 dP\"\"b8  dP\"Yb  88b 88  dP\"\"b8 88\"\"Yb    db    8888b.  88   88 88        db    888888 88  dP\"Yb  88b 88  d8b\n\
dP   `\" dP   Yb 88Yb88 dP   `\" 88__dP   dPYb    8I  Yb 88   88 88       dPYb     88   88 dP   Yb 88Yb88  Y8P\n\
Yb      Yb   dP 88 Y88 Yb  \"88 88\"Yb   dP__Yb   8I  dY Y8   8P 88.o    dP__Yb    88   88 Yb   dP 88 Y88  `\"'\n\
 YboodP  YbodP  88  Y8  YboodP 88  Yb dP\"\"\"\"Yb 8888Y\"  `YbodP' 88ood8 dP\"\"\"\"Yb   88   88  YbodP  88  Y8  (8)\n\
",  //  an ascii art
"\
 #####   #####  #    #  ######   ######     #    ######  #      # #          #    ####### ###  ######  #    # ##\n\
#     # #     # ##   # #     ##  #     #   # #   #     # #      # #         # #      #     #  #      # ##   # ##\n\
#       #     # # #  # #         #     #  #   #  #     # #      # #        #   #     #     #  #      # # #  # ##\n\
#       #     # #  # # #    #### ######  #     # #     # #      # #       #     #    #     #  #      # #  # # ##\n\
#       #     # #   ## #      #  #   #   ####### #     # #      # #       #######    #     #  #      # #   ##   \n\
#     # #     # #    # #      #  #    #  #     # #     # #      # #       #     #    #     #  #      # #    # ##\n\
 #####   #####  #    #  ######   #     # #     # ######   ######  ####### #     #    #    ###  ######  #    # ##\n\
",  //  an ascii art
    };

    //  Constructor
    Sudoku(int N, int K, int color)
    {
        aht = bc = c = 0;

        this->N = N;
        this->K = K;
        this->c = color;

        mat = new int* [N];
        ans = new int* [N];
        res = new int* [N];

        for (int i = 0; i < N; i++)
        {
            mat[i] = new int[N];
            ans[i] = new int[N];
            res[i] = new int[N];
        }

        //  reset the value
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                mat[i][j] = ans[i][j] = res[i][j] = 0;
            }
        }
    }

    //  Sudoku Generator
    void fill()
    {
        //  Fill the diagonal of sqrt(N) x sqrt(N) matrices
        fillDiagonal();

        // Fill remaining blocks
        fillr(0, sqrt(N));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans[i][j] = mat[i][j];
            }
        }

        //  remove K numbers to create quesion
        rkd();
    }

    //  fill the diagonal sqrt(N) number of sqrt(N) x sqrt(N) matrices
    void fillDiagonal()
    {
        for (int i = 0; i < N; i = i + sqrt(N))
        {
            // for diagonal box, start coordinates->i==j
            fillBox(i, i);
        }
    }

    //  fill a n*n matrix.
    void fillBox(int row, int col)
    {
        mt19937 mt(time(nullptr));
        int num;
        for (int i = 0; i < sqrt(N); i++) {
            for (int j = 0; j < sqrt(N); j++) {
                do {
                    num = mt() % N + 1;
                } while (!unb(row, col, num));
                mat[row + i][col + j] = num;
            }
        }
    }

    //  A recursive function to fill remaining matrix
    bool fillr(int i, int j)
    {
        // System.out.println(i+" "+j);
        if (j >= N && i < N - 1) {
            i = i + 1;
            j = 0;
        }
        if (i >= N && j >= N) {
            return true;
        }
        if (i < sqrt(N)) {
            if (j < sqrt(N)) {
                j = sqrt(N);
            }
        }
        else if (i < N - sqrt(N)) {
            if (j == (int)(i / sqrt(N)) * sqrt(N)) {
                j = j + sqrt(N);
            }
        }
        else {
            if (j == N - sqrt(N)) {
                i = i + 1;
                j = 0;
                if (i >= N) {
                    return true;
                }
            }
        }
        for (int num = 1; num <= N; num++) {
            if (cks(i, j, num)) {
                mat[i][j] = num;
                if (fillr(i, j + 1)) {
                    return true;
                }
                mat[i][j] = 0;
            }
        }
        return false;
    }

    //  check if safe to put in cell
    bool cks(int i, int j, int num)
    {
        int p = sqrt(N);
        return (
            unr(i, num) && unc(j, num)
            && unb(i - i % p, j - j % p, num));
    }

    //  return false if given n*n block contains num.
    bool unb(int rowStart, int colStart, int num)
    {
        for (int i = 0; i < sqrt(N); i++) {
            for (int j = 0; j < sqrt(N); j++) {
                if (mat[rowStart + i][colStart + j] == num)
                {
                    return false;
                }
            }
        }
        return true;
    }

    //  check in the row for existence
    bool unr(int i, int num)
    {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] == num)
            {
                return false;
            }
        }
        return true;
    }

    //  check in the row for existence
    bool unc(int j, int num)
    {
        for (int i = 0; i < N; i++) {
            if (mat[i][j] == num)
            {
                return false;
            }
        }
        return true;
    }

    //  create k blanks to complete game
    void rkd()
    {
        mt19937 mt(time(nullptr));
        int c = K;
        while (c > 0) {
            int i = mt() % N;
            int j = mt() % N;
            if (mat[i][j] != 0)
            {
                mat[i][j] = 0;
                c--;
            }
        }
    }

    //  print sudoku
    void ptSudoku(char a)
    {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (a == 'a')
                {
                    cout << "Now pt ans[][] : \n";
                    cout << setw(3) << to_string(ans[i][j]) + " ";
                }
                else if (a == 'm')
                {
                    cout << "Now pt mat[][] : \n";
                    cout << setw(3) << to_string(mat[i][j]) + " ";
                }
                else if (a == 'r')
                {
                    cout << "Now pt res[][] : \n";
                    cout << setw(3) << to_string(res[i][j]) + " ";
                }
                else
                {
                    cout << "It's strange since this function dosen't lnow what to print.";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    //  print something vertical
    void ptv(int n, char a) {
        for (int i = 0; i < ((n + 1) * (n + 1) + 2 * n * n); i++) {  //  i < n+1 + (n+1)*n + 2*n*n
            if (a == '-')
            {
                SetColor(13);
                cout << a;
            }
            else
            {
                cout << a;
            }
        }
        SetColor();
        cout << '\n';
    };

    //  print a line of blank or with words
    void ptb(int n, string s) {
        if (s.size() > ((n + 1) * (n + 1) + 2 * n * n - 2))
        {
            SetColor(13);
            cout << '|';
            SetColor(14);
            cout << s << endl;
            SetColor();
        }
        else
        {
            int bw = ((n + 1) * (n + 1) + 2 * n * n - 2) - s.size();
            SetColor(13);
            cout << "|";
            SetColor(14);
            cout << s;
            for (int i = 0; i < bw; i++) {
                cout << " ";
            }
            SetColor(13);
            cout << "|\n";
            SetColor();
        }
    };

    //  print congradulation
    void ptc() {
        time_t now = time(0);
        mt19937 mt(time(nullptr));
        SetColor(236);
        cout << '\n' << cgl[mt() % size(cgl)] << "\nYou completed a " << N << " * " << N << " Sudoku with " << now - clk << " seconds and " << aht << " hints.\n";
        SetColor();
        cout << '\n';

        for (int i = 0; i < N; i++) {
            delete[] mat[i];
            delete[] ans[i];
            delete[] res[i];
        }
        delete[] mat;
        delete[] ans;
        delete[] res;
    };

    //  print extra rules of 4*4 sudoku
    void ptr() {
        this->ptb(sqrt(N), "");
        this->ptb(sqrt(N), "use a for " + to_string(this->ctoi('a')) + ", b for " + to_string(this->ctoi('b')) + ", c for " + to_string(this->ctoi('c')) + ", d for " + to_string(this->ctoi('d')) + ",");
        this->ptb(sqrt(N), "    e for " + to_string(this->ctoi('e')) + ", f for " + to_string(this->ctoi('f')) + ", g for " + to_string(this->ctoi('g')) + ",");
        this->ptb(sqrt(N), "");
    };

    //  print the sudoku pattren
    void pt(int n, int x, int y, int uin) {
        //  basic setup
        this->ise = true;
        time_t now = time(0);

        //  put user input into arr
        if (uin != 0 && mat[x][y] == 0) {
            struct move tem;
            tem.ix = x;
            tem.jy = y;
            tem.in = uin;
            this->mbw.push(tem);
            while (!this->mfw.empty()) {
                this->mfw.pop();
            }
            res[x][y] = uin;
        }

        //  print the text above sudoku pattern
        if (n == 4)
        {
            this->ptr();
        }
        if (aht != 0)
        {
            this->ptb(sqrt(N), "You have asked for a hint " + to_string(aht) + " times.");
        }
        this->ptb(n, to_string(now - clk) + " seconds have passed since you start this turn.");
        this->ptv(n, '-');

        //  print the sudoku pattern
        for (int i = 0; i < N; i++) {
            SetColor(13);
            cout << "|";
            for (int j = 0; j < N; j++) {
                //  select which color can be used
                SetColor(c);
                if (i == x && j == y)
                {
                    SetColor(11);  //  where mouse is
                }
                else if (res[i][j] == ans[i][j] && res[i][j] != 0)
                {
                    SetColor(10);  //  correct answer
                }
                else if (res[i][j] != ans[i][j] && res[i][j] != 0)
                {
                    SetColor(12);  //  wrong answer
                }

                //  check if sudocu is completed
                if (res[i][j] + mat[i][j] != ans[i][j])
                {
                    ise = false;
                    bc++;
                }

                //  print a number
                if (mat[i][j] == 0 && res[i][j] == 0)
                {
                    cout << " __";
                }
                else
                {
                    cout << setw(3) << mat[i][j] + res[i][j];
                }
                SetColor();

                //  check if print a separate line
                if (j % n == n - 1) {
                    SetColor(13);
                    cout << " |";
                    SetColor();
                }
            }
            cout << endl;

            //  check if print a separate line
            if (i % n == n - 1)
            {
                this->ptv(n, '-');
            }
        }

        //  print the text below sudoku pattern
        this->ptb(n, "There are " + to_string(bc) + " blanks remaining.");
        this->ptb(n, "press 'ESC' to leave");
        this->ptb(n, "press 'H' to get a hint");
        this->ptb(n, "press 'Z' to undo an action");
        this->ptb(n, "press 'Y' to redo an action");
        this->ptv(n, '-');

        //  reset blank counter
        bc = 0;

        //  check if sudoku is completed
        if (ise)
        {
            this->ptc();
        }
    };

    //  set the color of output
    //  refrence website : https://blog.wildsky.cc/posts/c-code-note
    void SetColor(int color = 7) {
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }

    //  allow user to choose color used in the game
    int chc() {
        c = 16;
        cout << '\n';
        while (c < 256) {
            for (int i = 0; i < 16; i++) {
                if (c < 256) {
                    SetColor(c);
                    cout << "<" << setw(3) << c++ << ">";
                    SetColor();
                }
                else
                {
                    break;
                }
            }
            cout << '\n';
        }
        cout << "choose a color to show number in the following Sudoku from the chart above,\n\or ";
        SetColor(79);
        cout << "input 7";
        SetColor();
        cout << " to use basic color (press enter to sent your reply) : ";
        cin >> c;
        return c;
    };

    //  check if n belongs numbers to fill in
    int ctoi(char n) {
        n = toupper(n);
        if (n > 48 && n < 58)
        {
            return  n - '0';  //  if n belongs 1 ~ 9
        }
        else if (n > 64 && n < 72)
        {
            return 9 + n - '@';  //  if n belongs 10 ~ 16
        }
        else
        {
            return 0;
        }
    };

    //  work if someone ask for a hint
    void ah(int i, int j) {
        if (mat[i][j] != 0)
        {
            this->ptb(sqrt(N), "Your input h is an unvalid command.");
        }
        else {
            aht++;
            mat[i][j] = ans[i][j];
        }
    };

    //  undo
    void cz() {
        if (!this->mbw.empty())
        {
            //mbw.top().ix;
            x = mbw.top().ix;
            y = mbw.top().jy;
            this->res[x][y] = 0;
            //this->res[x][y] = mbw.top().in;
            struct move tem;
            tem.ix = mbw.top().ix;
            tem.jy = mbw.top().jy;
            tem.in = mbw.top().in;
            this->mfw.push(tem);
            this->mbw.pop();
        }
        else
        {
            this->ptb(sqrt(N), "Your input Z is an unvalid command.");
        }
    };

    //  redo
    void cy() {
        if (!this->mfw.empty())
        {
            x = mfw.top().ix;
            y = mfw.top().jy;
            this->res[x][y] = mfw.top().in;
            struct move tem;
            tem.ix = mfw.top().ix;
            tem.jy = mfw.top().jy;
            tem.in = mfw.top().in;
            this->mbw.push(tem);
            this->mfw.pop();
        }
        else
        {
            this->ptb(sqrt(N), "Your input Y is an unvalid command.");
        }
    };
};
