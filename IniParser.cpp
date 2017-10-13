#include "IniParser.h"
#include <iostream>
#include <string> // подключаем строки
#include <fstream> // подключаем файлы
#include <stdlib.h>



using namespace std; // используем стандартное пространство имен
IniParser::IniParser(char* inp)

{
    string section;
    string s; // сюда будем класть считанные строки
    ifstream file(inp); // файл из которого читаем

    while(getline(file, s)){ // пока не достигнут конец файла класть очередную строку в переменную (s)
        //cout << s << endl; // выводим на экран
        if (s[0] == '['){
            cout << "Section: " <<(section = s.substr(1,s.length()-2)) << endl;
        }
        else {
            if (s.find(";") != -1)
                s=s.substr(0,s.find(";")); //Удаляем комментарии
            if (s.find("=") != -1)//Если строка содержит параметр
            {
                while (s.find(" ") != -1)
                    s.erase(s.find(" "),1); //Удаляем пробелы
                cout << "Param: " << section << "." << s.substr(0,s.find("=")) << " Value: " << s.substr(s.find("=")+1) <<endl;
                setValue(section, s.substr(0,s.find("=")),s.substr(s.find("=")+1));

            }
        }
    }

    file.close(); // обязательно закрываем файл что бы не повредить его
}

void IniParser::printAll()
{
    cout << "Printall--------------------" << endl;
    for ( map<string, map<string, string> >::iterator it = data.begin(); it != data.end(); ++it)
    {
        cout << "section: " << it->first << endl;
        for ( map<string, string>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
        {
            cout << "Param: " << it2->first << " " << it2->second << endl;
        }


    }
}

void IniParser::setValue(string setSection, string setParam, string setParamValue)
{
    data[setSection][setParam]=setParamValue;
}
string IniParser::getString(string getSection, string getParam)
{
    if (data.count(getSection) == 0)
        throw IniParserExeptionNoSuchParam("No such section: "+getSection);
    if (data[getSection].count(getParam) == 0)
        throw IniParserExeptionNoSuchParam("No such param: "+getParam);
    return data[getSection][getParam];
}
int IniParser::getInt(string getSection, string getParam)
{
    string s1 = getString(getSection, getParam);
    const char* s = s1.c_str();
    int result = atoi(s);
    if (result == 0)
    {
        bool all0 = true;
        for (int i=0; s[i] !='\0'; i++)
        {
            if (s[i] != '0')
                all0 = false;
        }
        if(all0 == false)
            throw IniParserExeptionConvertationError("Convertation error Int: "+s1);
    }
    return result;
}
double IniParser::getDouble(string getSection, string getParam)
{
    string s1 = getString(getSection, getParam);
    const char* s = s1.c_str();
    double result = atof(s);
    if (result == 0)
    {
        bool all0 = true;
        int dotCount=0;
        for (int i=0; s[i] !='\0'; i++)
        {
            if (s[i] == '.')
                dotCount++;
            else
                if (s[i] != '0')
                    all0 = false;
        }
        if(all0 == false || dotCount >= 2)
            throw IniParserExeptionConvertationError("Convertation error Float: "+s1);
    }
    //free((void*)s);
    return result;
}

IniParser::~IniParser()
{
    //dtor
    data.clear();
}
