#include<stdio.h>
#include<string.h>
int main() {
char str[100];
int length = 0;
int isPalindrome = 1;
printf("Enter a string: ");
fgets(str, 100, stdin);
length = strlen(str);
if (length > 0 && str[length - 1] == '\n') {
str[length - 1] = '\0';
}
length = strlen(str);
int start = 0;
int end = length - 1;
while (start < end) {
if (str[start] != str[end]) {
isPalindrome = 0;
break;
}
start++;
end--;
}
if (isPalindrome == 1) {
printf("The string \"%s\" is a palindrome.\n", str);
} else {
printf("The string \"%s\" is NOT a palindrome.\n", str);
}
return 0;
}
