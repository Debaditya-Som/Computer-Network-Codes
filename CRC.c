#include <stdio.h>
#include <string.h>
int main() {
    int divl, dl, i, j;
    char data[50], divisor[50], originalData[50];
    printf("Enter codeword: ");
    scanf("%s", data);
    strcpy(originalData, data); // Store the original data for later use
    dl = strlen(data);
    printf("Enter divisor: ");
    scanf("%s", divisor);
    divl = strlen(divisor);

    // Append zeros to the data word for CRC calculation
    for (i = 0; i < divl - 1; i++) {
        data[dl + i] = '0';
    }
    data[dl + divl - 1] = '\0'; // Null-terminate the updated data
    dl = strlen(data);
    // CRC calculation
    for (i = 0; i <= dl - divl; i++) {
        if (data[i] == '1') {
            for (j = 0; j < divl; j++) {
                if (data[i + j] == divisor[j])
                    data[i + j] = '0'; // XOR operation
                else
                    data[i + j] = '1'; // XOR operation
            }
        }
    }

    // Extract the CRC remainder from the data
    char remainder[50];
    for (i = dl - divl + 1, j = 0; i < dl; i++, j++) {
        remainder[j] = data[i];
    }
    remainder[j] = '\0'; // Null-terminate the remainder

    // Display the updated codeword (original data + remainder)
    strcat(originalData, remainder); // Append the remainder to the original data
    printf("Updated codeword (with CRC): %s\n", originalData);

    // Check the remainder to verify CRC
    int remainderSum = 0;
    for (i = 0; i < strlen(remainder); i++)
        remainderSum += remainder[i] - '0'; // Convert char to int and sum the remainder bits
    
    if (remainderSum == 0)
        printf("CRC check passed! No errors detected.\n");
    else 
        printf("CRC check failed! Errors detected.\n");
    return 0;
}
