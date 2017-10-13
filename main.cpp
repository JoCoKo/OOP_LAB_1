#include <iostream>
#include <string> // подключаем строки
#include <fstream> // подключаем файлы
#include "IniParser.h"



using namespace std; // используем стандартное пространство имен
/*
void inOut(char* inp)
{
    string section;
    string s; // сюда будем класть считанные строки
    ifstream file(inp); // файл из которого читаем

    while(getline(file, s)){ // пока не достигнут конец файла класть очередную строку в переменную (s)
        cout << s << endl; // выводим на экран
        if (s[0] == '['){
            cout << "Section: " <<(section = s.substr(1,s.length()-2)) << endl;
        }
        else {
            if (s.find("=") != -1)//Если строка содержит параметр
            {
                if (s.find(";") != -1)
                    s=s.substr(0,s.find(";")); //Удаляем комментарии
                while (s.find(" ") != -1)
                    s.erase(s.find(" "),1); //Удаляем пробелы
                cout << "Param: " << section << "." << s.substr(0,s.find("=")) << " Value: " << s.substr(s.find("=")+1) <<endl;
            }
        }
    }

    file.close(); // обязательно закрываем файл что бы не повредить его
}*/
int main()
{
    /*char inp[255];
    cin >> inp;
    cout << "String input: " << inp << endl;
    inOut(inp);
    inOut("inpf.txt"); */
    char * sin = (char*)"lab01_input_correct.ini";
    IniParser parser = IniParser(sin);
    parser.printAll();
    try
    {
    cout << parser.getDouble("COMMON", "StatisterTimeMs") << endl;
//    cout << parser.getString("COMMON", "StatisterTimeMS") << endl;
    }
    catch (IniParserExeptionNoSuchParam& e)
    {
        cerr << e.get() << endl;
    }
    try
    {
    cout << parser.getString("COMMOn", "StatisterTimeMS") << endl;
    }
    catch (IniParserExeptionNoSuchParam& e)
    {
        cerr << e.get() << endl;
    }
	getchar();

    return 0;
}
