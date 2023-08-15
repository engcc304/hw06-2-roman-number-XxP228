/*
    ผู้ใช้กรอกตัวเลขเข้ามาในระบบ และให้คุณแปลงตัวเลขดังกล่าวให้เป็นตัวเลขโรมัน
    (โจทย์ข้อนี้ให้ใช้ For Loop เท่านั้น)

    Test case:
        8
    Output:
        8 = VIII

    Test case:
        4
    Output:
        4 = IV

    Test case:
        514
    Output:
        514 = DXIV

    Test case:
        929
    Output:
        929 = CMXXIX

*/
#include <stdio.h>

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);
    if (num < 1 || num > 3999)
    {
        printf("Invalid input.\n");
        return 1;
    }
    printf("%d = ", num);
    char romanS[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int romanV[] = {1000, 500, 100, 50, 10, 5, 1};
    for (int i = 0; i < 7; i += 2)
    {
        int digit = num / romanV[i];
        num %= romanV[i];

        if (digit == 9)
        {
            printf("%c%c", romanS[i], romanS[i - 2]);
        }
        else if (digit >= 5)
        {
            printf("%c", romanS[i - 1]);
            for (int j = 6; j <= digit; j++)
            {
                printf("%c", romanS[i]);
            }
        }
        else if (digit == 4)
        {
            printf("%c%c", romanS[i], romanS[i - 1]);
        }
        else
        {
            for (int j = 1; j <= digit; j++)
            {
                printf("%c", romanS[i]);
            }
        }
    }

    printf("\n");

    return 0;
}
