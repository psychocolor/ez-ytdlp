# ez-ytdlp

## description
simple CLI wrapper for yt-dlp to quickly download audio/video without having to remember command-line flags. the program provides a simple interface that lets you choose a format to download (mp3/mp4) and then lets you enter a link. that link is then forwarded to pre-configured yt-dlp flags and then the full command is executed using the C++ 'system()' function (note: i am aware the 'system()' function is unsafe because of command injection, this project was made for my own personal use.)

## prerequisites
- [yt-dlp](https://github.com/yt-dlp/yt-dlp)
- [FFmpeg](https://www.ffmpeg.org/)

## how to run
1. clone the repository.
2. compile source code using a compiler of your choice (in this case g++).
```bash
g++ -o ez-ytdlp main.cpp 
```
3. run the executable.
```bash
./ez-ytdlp
```
4. (optional) add the executable to your system's PATH for easy access anywhere.

## disclaimer
this project was made as a learning exercise and for my own personal use. all credit for its downloading functionality goes to the creators of [yt-dlp](https://github.com/yt-dlp/yt-dlp) and [FFmpeg](https://www.ffmpeg.org/)