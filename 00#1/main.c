#include<stdio.h>

int main()
{
    //Variable Declaration
    int input;

    int a, b, c, d, e;      //Note: e = check digit

    int checkdigit_value;

    //Asking for Input
    printf("Enter a 5 digit number: ");
    scanf("%d", & input);

    //Input Validation
    while(input < 10000 || input > 99999)
    {
        printf("Wrong input, please try again: ");
        scanf("%d", & input);
    }

    //Extracting Check digit
    e = input % 10;     //Some simple logic here: "%" or modulus gives the remainder of division,
                        //So when the input, i.e.29654 is divided by 10, the remainder is 4, the last digit.

    //Extracting First Four Digits
    a = input / 10000;          //The same logic here, when i.e.29654 is divided by 10000, the answer is 2.9654,
                                //As it is an integer it does matter what the numbers after the decimal place are, only the 2 is taken.
    b = (input / 1000) % 10;    //The same thing is done, but 29 is the taken, and then remainder by using modulus is 9
    c = (input / 100) % 10;   // And continue so on...
    d = (input / 10) % 10;

    //Printing the Digits
    printf("\nThe check digit is: %d", e);
    printf("\nThe first four digits are: %d, %d, %d, %d", a, b, c, d);

    //Calculating the check digit
    checkdigit_value = (a * 1) + (b * 2) + (c * 3) + (d * 4) + (e * 5);     //Just adding the numbers after multiplying by position value
    checkdigit_value = checkdigit_value % 10;       //Taking the last digit of the sum as check digit

    //Comparing the input's check digit (aka "e") with our calculated check digit (aka "checkdigit_value")
    if(e == checkdigit_value)
    {
        printf("\n\nThe check digits have matched.\n");
    }

    {
        printf("\n\nThe check digits have not matched.\n");
    }

    return 0;       //Additional Notes: "||" symbol is "or" operator, "==" is the comparison operator, "\n" is for newline
}
