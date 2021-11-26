#ifndef __CORE__H__
#define __CORE__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#include <iostream>
#include <string>

#define HTTP_200 "HTTP/1.0 200 OK\n"
#define HTTP_404 "HTTP/1.0 404 Not found\n"
#define HTTP_301 "HTTP/1.0 301 Moved Permanently\n"
#define HTTP_500 "HTTP/1.0 500 Server error\n"

#define URL_ILLEGAL "URL_ILLEGAL"

#define Const_date_size 1024

#define ETCDIR "../etc/"

#define INDEX_PATH "../etc/web/login.htm"
#define log_csv "../etc/log.csv"

using namespace std;

const char *wday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thurday", "Friday", "Saturday"};

string findHost(char *text)
{
    size_t len = strlen(text);
    string str;
    size_t i = 0;
    while (i <= len)
    {
        if (text[i] == 'H')
        {
            string str_2;
            str_2 = str_2 + text[i] + text[i + 1] + text[i + 2] + text[i + 3] + text[i + 4] + text[i + 5];
            if (str_2 == "Host: ")
            {
                size_t j = i + 6;
                while (j <= len - i - 6)
                {
                    if (text[j] != '\n')
                    {
                        str = str + text[j];
                    }
                    else
                    {
                        break;
                    }
                    j++;
                }
                break;
            }
        };
        i++;
    }
    char *p = strrchr(str.c_str(), '/');
    if (p != NULL)
    {
        string s(p);
        if (s.length() == 0)
        {
            return INDEX_PATH;
        }
        else
        {
            return ETCDIR + s;
        }
    }
    else
    {
        return INDEX_PATH;
    }
}

char *getFileType(string fileName)
{
    char *p = strrchr(fileName.c_str(), '.');
    if (p == NULL)
    {
        return NULL;
    }
    return p;
}

string getHeader(const char *fn)
{
    string header = "";
    time_t timep;
    time(&timep);
    struct tm *p = gmtime(&timep);
    header = header + "Date: " + to_string(1900 + p->tm_year) + "/" + to_string(1 + p->tm_mon) + "/" + to_string(p->tm_mday) + " " + wday[p->tm_wday] + " " + to_string(p->tm_hour + 8) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + " UTC+8 times of Beijing China\n";
    header = header + "Server: CXX SOCKET TCP HTTP Server::NULL_NAME\n";
    if (fn == NULL)
    {
        header = header + "Content-Type: " + "text/plain\n";
    }
    if (strcmp(fn, ".jpeg") == 0 | strcmp(fn, ".jpg") == 0)
    {
        header = header + "Content-Type: " + "image/jpeg\n";
    }
    else if (strcmp(fn, ".png") == 0)
    {
        header = header + "Content-Type: " + "image/png\n";
    }
    else if (strcmp(fn, ".gif") == 0)
    {
        header = header + "Content-Type: " + "image/gif\n";
    }
    else if (strcmp(fn, ".htm") == 0 | strcmp(fn, ".html") == 0)
    {
        header = header + "Content-Type: " + "text/html\n";
    }
    else if (strcmp(fn,".xml") == 0)
    {
        header = header + "Content-Type: " + "text/xml\n";
    }
    else if (strcmp(fn,".exe") == 0 | strcmp(fn,".o") == 0 | strcmp(fn,".out") == 0 
    | strcmp(fn,"iso") == 0 | strcmp(fn,".dmg") == 0 | strcmp(fn,".zip") == 0| strcmp(fn,".7z") == 0
    )
    {
        header = header + "Content-Type: " + "application/octet-stream\n";
    }
    else if (fn == ".js")
    {
        header = header + "Content-Type: " + "application/javascript\n";
    }
    header = header + "\r\n\r\n";
    return header;
};
string getFILE(const char *filepath)
{
    char *html = NULL;
    string str_html;
    FILE *fp = fopen(filepath, "r");
    char * ft = getFileType(filepath);
    if (filepath == URL_ILLEGAL)
    {
        str_html = str_html + HTTP_404 + getHeader(ft);
        str_html += "<h1>The url illegal or no this file.</h1>";
        return str_html;
    }
    if (fp == NULL)
    {
        str_html = str_html + HTTP_404 + getHeader(ft);
        str_html += "<h1>The url illegal or no this file.</h1>";
    }
    else
    {
        str_html = str_html + HTTP_200 + getHeader(ft);
        fseek(fp, 0L, SEEK_END);
        const size_t flen = ftell(fp);
        html = (char *)malloc(flen + 1);
        rewind(fp);
        fread(html, flen, 1, fp);
        str_html = str_html + html;
        if (strstr(str_html.c_str(), html) != NULL)
        {
            free(html);
        }
    }
    fclose(fp);
    return str_html;
};

#endif //!__CORE__H__