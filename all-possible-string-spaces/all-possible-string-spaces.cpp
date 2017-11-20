void printSpaceUntil(char str[], char buffer[], int i, int j, int len) {
    if(i == len) {
        buffer[j] = '\0';
        cout << buffer << "$";
        return;
    }

    buffer[j] = str[i];
    printSpaceUntil(str, buffer, i+1, j+1, len);

    buffer[j] = ' ';
    buffer[j+1] = str[i];
    printSpaceUntil(str, buffer, i+1, j+2, len);
}



void  printSpace(char str[])
{
//Your code here
    int len = strlen(str);
    char buffer[len*2];

    buffer[0] = str[0];

    printSpaceUntil(str, buffer, 1, 1, len);
}

int main () {
  char str[] = "ABCD";
  printSpace(str);
  return 0;
}
