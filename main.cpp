#include <iostream>
#include <string>
#include <limits>

void downloadVideo(std::string flags)
{
    std::string link{};
    
    while (true)
    {
        std::cout << "enter a link: ";
        std::cin >> link;

        if (link.find("https://") == std::string::npos || link.find_first_of(";&|`$\"") != std::string::npos)
        { 
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "[!] invalid link. try again\n";
            continue;
        }

        break;
    }

    flags += "\"" + link + "\"";
    
    const char* command{flags.c_str()};
    system(command);

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
        std::cout << "(3) exit\n";
        std::cout << "choice: ";

        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "[!] invalid input. try again\n";
            continue;
        }

        switch(choice)
        {
            case 1:
            {
                downloadVideo("yt-dlp -x --audio-format mp3 ");
                std::cout << "[+] audio downloaded successfully!\n";
                break;
            }
            case 2:
            {
                downloadVideo("yt-dlp -f \"bestvideo[ext=mp4]+bestaudio[ext=m4a]/best[ext=mp4]/best\" ");
                std::cout << "[+] video downloaded successfully!\n";
                break;
            }
            case 3:
            {
                std::cout << "byebye\n";
                return;
                break;
            }
            default:
            {
                std::cout << "[!] invalid input. try again\n";
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