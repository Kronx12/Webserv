#ifndef CGI_HPP
#define CGI_HPP

#include "global.hpp"

class Client;

class CGI {
    public:
        CGI();
        bool operator()(std::string path, Route &conf);
        CGI(const CGI &cgi);
        CGI &operator=(const CGI &cgi);
        ~CGI();

        void setFrom(Client &c, std::string path, Route *conf, char **env, std::map<std::string, std::string> headers, std::string args);
        char **getArgs();
        std::string parseResult(std::string);

        std::string process();
        int _errno;

    private:
        std::map<std::string, std::string> _mapped_args;
        std::string _content;
        Route *_road;
};

#endif // !CGI_HPP
