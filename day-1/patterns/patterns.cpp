#include <bits/stdc++.h>
using namespace std;
/* pattern 1
 * * * * *
 * * * * *
 * * * * *
 * * * * *
 * * * * *
 */
void pattern1(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "* ";
    }
    cout << endl;
  }
}
/* pattern 2
 *
 * *
 * * *
 * * * *
 */
void pattern2(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      cout << "* ";
    }
    cout << endl;
  }
}
/* pattern 3
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
*/
void pattern3(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << j << " ";
    }
    cout << endl;
  }
}
/* pattern 4
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
*/
void pattern4(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << i << " ";
    }
    cout << endl;
  }
}
/* pattern 5
 * * * * *
 * * * *
 * * *
 * *
 *
 */
void pattern5(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n - i + 1; j++) {
      cout << "* ";
    }
    cout << endl;
  }
}
/* pattern 6
0 1 2 3 4
0 1 2 3
0 1 2
0 1
0
*/
void pattern6(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n - i + 1; j++) {
      cout << j << " ";
    }
    cout << endl;
  }
}
/* pattern 7
 *
 ***
 *****
 *******
 *********
 */
void pattern7(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }
    for (int star = 0; star < 2 * i + 1; star++) {
      cout << "*";
    }
    for (int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }
    cout << endl;
  }
}
/* pattern 8
*********
*******
*****
***
*
*/
void pattern8(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    for (int star = 0; star < 2 * n - (2 * i + 1); star++) {
      cout << "*";
    }
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    cout << endl;
  }
}
/* pattern 9
 *
 ***
 *****
 *******
 *********
 *********
 *******
 *****
 ***
 *
 */
void pattern9(int n) {
  pattern7(n);
  pattern8(n);
}
/* pattern 10
 *
 **
 ***
 ****
 *****
 ****
 ***
 **
 *
 */
void pattern10(int n) {
  for (int i = 0; i <= 2 * n - 1; i++) {
    int stars = i;
    if (i > n) stars = 2 * n - i;
    for (int j = 0; j < stars; j++) {
      cout << "*";
    }
    cout << endl;
  }
}
/* pattern 11
1
10
010
0101
*/
void pattern11(int n) {
  int start = 1;
  for (int i = 0; i < n; i++) {
    start = (start % 2 == 0) ? 1 : 0;
    for (int j = 0; j < i; j++) {
      cout << start;
      start = 1 - start;
    }
    cout << endl;
  }
}
/* pattern 12
1        1
12      21
123    321
1234  4321
1234554321
*/
void pattern12(int n) {
  int space = 2 * (n - 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << j;
    }
    for (int j = 1; j <= space; j++) {
      cout << " ";
    }
    for (int j = i; j >= 1; j--) {
      cout << j;
    }
    cout << endl;
    space -= 2;
  }
}
/* pattern 13
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/
void pattern13(int n) {
  int num = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << num << " ";
      num++;
    }
    cout << endl;
  }
}
/* pattern 14
A
A B
A B C
A B C D
A B C D E
*/
void pattern14(int n) {
  for (int i = 0; i < n; i++) {
    for (char ch = 'A'; ch <= 'A' + i; ch++) {
      cout << ch << " ";
    }
    cout << endl;
  }
}
/* pattern 15
A B C D E
A B C D
A B C
A B
A
*/
void pattern15(int n) {
  for (int i = 0; i < n; i++) {
    for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++) {
      cout << ch << " ";
    }
    cout << endl;
  }
}
/* pattern 16
A
B B
C C C
D D D D
E E E E E
*/
void pattern16(int n) {
  for (int i = 0; i < n; i++) {
    char ch = 'A' + i;
    for (int j = 0; j <= i; j++) {
      cout << ch << " ";
    }
    cout << endl;
    ch++;
  }
}
/* pattern 17
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/
void pattern17(int n) {
  // space
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }
    // letter
    char ch = 'A';
    int breakpoint = (2 * i + 1) / 2;
    for (int j = 1; j <= (2 * i + 1); j++) {
      cout << ch;
      if (j <= breakpoint) {
        ch++;
      } else
        ch--;
    }
    // space
    for (int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }
    cout << endl;
  }
}
/* pattern 18
E
D E
C D E
B C D E
A B C D E
*/
void pattern18(int n) {
  for (int i = 0; i < n; i++) {
    for (char ch = 'A' + n - i - 1; ch <= 'A' + n - 1; ch++) {
      cout << ch << " ";
    }
    cout << endl;
  }
}
/* pattern 19
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/
void pattern19(int n) {
  int spaces = 0;
  for (int i = 0; i < n; i++) {
    // stars
    for (int j = 1; j <= n - i; j++) {
      cout << "*";
    }
    // spaces
    for (int j = 0; j < spaces; j++) {
      cout << " ";
    }
    // stars
    for (int j = 1; j <= n - i; j++) {
      cout << "*";
    }
    spaces += 2;
    cout << endl;
  }
  // second half
  spaces = 2 * n - 2;
  for (int i = 1; i <= n; i++) {
    // stars
    for (int j = 1; j <= i; j++) {
      cout << "*";
    }
    // spaces
    for (int j = 0; j < spaces; j++) {
      cout << " ";
    }
    // stars
    for (int j = 1; j <= i; j++) {
      cout << "*";
    }
    spaces -= 2;
    cout << endl;
  }
}
/* pattern 20
 *        *
 **      **
 ***    ***
 ****  ****
 **********
 ****  ****
 ***    ***
 **      **
 *        *
 */
void pattern20(int n) {
  int spaces = 2 * n - 2;
  for (int i = 1; i <= 2 * n - 1; i++) {
    int stars = i;
    if (i > n) stars = 2 * n - i;
    // stars
    for (int j = 1; j <= stars; j++) {
      cout << "*";
    }
    // spaces
    for (int j = 1; j <= spaces; j++) {
      cout << " ";
    }
    // stars
    for (int j = 1; j <= stars; j++) {
      cout << "*";
    }
    cout << endl;
    if (i < n)
      spaces -= 2;
    else
      spaces += 2;
  }
}
/* pattern 21
 * * * * *
 *       *
 *       *
 *       *
 * * * * *
 */
void pattern21(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
}
/* pattern 22
5 5 5 5 5 5 5 5 5
5 4 4 4 4 4 4 4 5
5 4 3 3 3 3 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 2 1 2 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 3 3 3 3 4 5
5 4 4 4 4 4 4 4 5
5 5 5 5 5 5 5 5 5
*/
void pattern22(int n) {
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      int top = i;
      int left = j;
      int right = (2 * n - 2) - j;
      int bottom = (2 * n - 2) - i;
      cout << (n - min(min(top, bottom), min(left, right))) << " ";
    }
    cout << endl;
  }
}
/* pattern 23
1 2 3 4 5 6 7
1 2 3 4 5 6
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5 6 7
*/
void pattern23(int n) {
  for (int i = 1; i <= 2 * n - 1; i++) {
    int condition = n + 1 - i;
    if (i > n) condition = i - n + 1;
    for (int j = 1; j <= condition; j++) {
      cout << j << " ";
    }
    cout << endl;
  }
}
/* pattern 24
   A
  A B
 A B C
A B C D
 A B C
  A B
   A
*/
void pattern24(int n) {
  int counter = 0;
  for (int i = 1; i <= 2 * n - 1; i++) {
    // space
    for (int j = 0; j < abs(2 * n - n - i); j++) {
      cout << " ";
    }
    // letter
    for (char ch = 'A'; ch <= 'A' + counter; ch++) {
      cout << ch << " ";
    }
    if (i >= n)
      counter--;
    else
      counter++;
    cout << endl;
  }
}
/* pattern 25
1 2 3 4
 1 2 3
  1 2
   1
  1 2
 1 2 3
1 2 3 4
*/
void pattern25(int n) {
  int space = 0;
  for (int i = 1; i <= 2 * n - 1; i++) {
    // space
    for (int j = 0; j < space; j++) {
      cout << " ";
    }
    // number
    for (int j = 1; j <= n - space; j++) {
      cout << j << " ";
    }
    if (i >= n)
      space--;
    else
      space++;
    cout << endl;
  }
}

int main() {
  int n;
  cin >> n;
  // pattern1(n);
  // pattern2(n);
  // pattern3(n);
  // pattern4(n);
  // pattern5(n);
  // pattern6(n);
  // pattern7(n);
  // pattern8(n);
  // pattern9(n);
  // pattern10(n);
  // pattern11(n);
  // pattern12(n);
  // pattern13(n);
  // pattern14(n);
  // pattern15(n);
  // pattern16(n);
  // pattern17(n);
  // pattern18(n);
  // pattern19(n);
  // pattern20(n);
  // pattern21(n);
  // pattern22(n);
  // pattern23(n);
  // pattern24(n);
  // pattern25(n);
}