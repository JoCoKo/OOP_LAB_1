#ifndef INIPARSER_H
#define INIPARSER_H
#include <map>
#include <string>

using namespace std;

class IniParserExeptionNoSuchParam
{
public:
    IniParserExeptionNoSuchParam(const string& msg)
    {
        message=msg;
    }
    string get()
    {
        return message;
    }

private:
    string message;
};

class IniParserExeptionConvertationError
{
public:
    IniParserExeptionConvertationError(const string& msg)
    {
        message=msg;
    }
    string get()
    {
        return message;
    }

private:
    string message;
};

class IniParser
{
    public:
        IniParser(char* fileName);
        virtual ~IniParser();
        void setValue(string, string, string);
        string getString(string, string);
        int getInt(string, string);
        double getDouble(string, string);
        void printAll();

    protected:

    private:
        map<string, map<string, string> > data;

};

#endif // INIPARSER_H
