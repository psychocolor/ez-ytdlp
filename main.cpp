#include <iostream>
#include <string>
#include <limits>

void commandFailCheck(int result)
{
    switch (result)
    {
        case -1:
        {
            std::cerr << "[-] Error. Couldn't open command line.\n";
            break;
        }
        case 0:
        {
            std::cout << "[+] File downloaded successfully!\n";
            break;
        }
        case 1:
        {
            std::cerr << "[-] Error. Couldn't download file, read above for details.\n";
            break;
        }
    }
}

void downloadVideo(std::string flags)
{
    std::string link{};
    
    while (true)
    {
        std::cout << "Enter a link: ";
        std::cin >> link;

        if (link.find("https://") == std::string::npos || link.find_first_of(";&|`$\"") != std::string::npos)
        { 
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "[!] Invalid link. Try again\n";
            continue;
        }

        break;
    }

    flags += "\"" + link + "\"";
    
    const char* command{flags.c_str()};
    int result{system(command)};
    commandFailCheck(result);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void menu()
{    
    while (true)
    {
        int choice{};
        std::cout << "\033[36m" << "ez-ytdlp\n" << "\033[0m";
        std::cout << "(1) mp3\n";
        std::cout << "(2) mp4\n";
        std::cout << "(3) Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "[!] Invalid input. Try again\n";
            continue;
        }

        switch(choice)
        {
            case 1:
            {
                downloadVideo("yt-dlp -x --audio-format mp3 ");
                break;
            }
            case 2:
            {
                downloadVideo("yt-dlp -f \"bestvideo[ext=mp4]+bestaudio[ext=m4a]/best[ext=mp4]/best\" ");
                break;
            }
            case 3:
            {
                std::cout << "Bye-bye!\n";
                return;
                break;
            }
            default:
            {
                std::cerr << "[!] Choice out of range. Try again\n";
                break;
            }
        }
    } 
}

int main()
{
    menu();
    return 0;
}