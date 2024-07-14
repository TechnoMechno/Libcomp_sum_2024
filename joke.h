#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "c_curl_downloader_win_linux/curl_downloader_alt.h"

#ifndef JOKE_H
#define JOKE_H

void writeJoke(){
    const char* url_str = "https://icanhazdadjoke.com/";
    const char* file_output_name = "joke_file.txt";
    if (!curl_download(file_output_name, url_str)) {
        throw std::runtime_error("Failed to download file");
    }
}

std::string getJoke(){
    // Read txt file
    std::ifstream file("joke_file.txt");
    if (!file.is_open()){
        throw std::runtime_error("Failed to open file");
    }
    // Return joke
    std::stringstream jokeBuffer;

    jokeBuffer << file.rdbuf();
    file.close();

    return jokeBuffer.str();
}
#endif


