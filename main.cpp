#include <iostream>
#include <chrono>

#define start_symbol 48
#define end_symbol 122

unsigned int charIndex = 0;
unsigned int tempIndex = 0;

void changeInDepth(char* ch)
{
    if((int)ch[tempIndex] == end_symbol)
    {
        if(tempIndex == 0)
        {
            ch[charIndex] = start_symbol;
            charIndex++;
            ch[tempIndex] = start_symbol;
            ch[charIndex] = start_symbol;
            ch[charIndex+1] = '\0';
        }
        else
        {
            ch[tempIndex] = start_symbol;
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
    system("cls");
    
    char* ch = new char[64];
    auto start_time = std::chrono::steady_clock::now();

    while (strcmp(ch, password.c_str()) != 0)
    {
        for (int i = start_symbol; i <= end_symbol; i++)
        {
            ch[charIndex] = i;
            std::cout << ch << "\r";
            if(strcmp(ch, password.c_str()) == 0)
            {
                std::cout << std::endl << "Password found: " << ch << std::endl;
                auto end_time = std::chrono::steady_clock::now();
                auto elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
                std::cout << std::endl << "Elapsed Time: " << elapsed_ns.count() << " s\n";
                return 0;
            }
        }
        if (charIndex > 0)
            tempIndex = charIndex-1;
        changeInDepth(ch);
    }

    return 0;
}

