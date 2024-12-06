#include <iostream>

#define ascii_a 97
#define ascii_z 122

unsigned int charIndex = 0;
unsigned int tempIndex = 0;

void changeInDepth(char* ch)
{
    if((int)ch[tempIndex] == ascii_z)
    {
        if(tempIndex == 0)
        {
            ch[charIndex] = ascii_a;
            charIndex++;
            ch[tempIndex] = ascii_a;
            ch[charIndex] = ascii_a;
            ch[charIndex+1] = '\0';
        }
        else
        {
            ch[tempIndex] = ascii_a;
            tempIndex--;
            changeInDepth(ch);
        }
    }
    else
    {
        ch[tempIndex] = (int)ch[tempIndex] + 1;
    }
}

int main()
{
    std::string password;
    std::cout << "Enter password:\n";
    std::cin >> password;

    const int iterationCount = 100000;
    
    char* ch = new char[64];

    system("cls");

    for (int k = 0; k < iterationCount; k++)
    {
        for (int i = ascii_a; i <= ascii_z; i++)
        {
            ch[charIndex] = i;
            std::cout << ch << "\r";
            if(strcmp(ch, password.c_str()) == 0)
            {
                std::cout << std::endl << 
                "----------------" << std::endl << 
                "Password found: " << ch << " iterations: " << k << std::endl << 
                "----------------" << std::endl;
                return 0;
            }
        }
        if (charIndex > 0)
            tempIndex = charIndex-1;
        changeInDepth(ch);
    }
    std::cout << std::endl << "Password not found" << std::endl;

    return 0;
}

