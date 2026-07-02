# ez-ytdlp

## Description
Simple CLI wrapper for yt-dlp to quickly download audio/video without having to remember command-line flags. The program provides a simple interface that lets you choose a format to download (mp3/mp4) and then lets you enter a link. That link is then forwarded to pre-configured yt-dlp flags and then the full command is executed using the C++ 'system()' function (NOTE: I am aware the 'system()' function is unsafe because of command injection, this project was made for my own personal use.)

## Prerequisites
- [yt-dlp](https://github.com/yt-dlp/yt-dlp)
- [FFmpeg](https://www.ffmpeg.org/)

## How to run
1. Clone the repository.
2. Compile source code using a compiler of your choice (in my case g++).
```bash
g++ -o ez-ytdlp main.cpp 
```
3. Run the executable.
```bash
./ez-ytdlp
```
4. (Optional) Add the executable to your system's PATH for easy access anywhere.

## Disclaimer
This project was made as a learning exercise and for my own personal use. All credit for its downloading functionality goes to the creators of [yt-dlp](https://github.com/yt-dlp/yt-dlp) and [FFmpeg](https://www.ffmpeg.org/)