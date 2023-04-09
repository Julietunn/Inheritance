#include<iostream>
#include<fstream>
using namespace std;

#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//если нужно вводить имя файла с клавиатуры
	char filename[_MAX_FNAME] = {};
	cout << "Введите имя файла: "; 
	cin.getline(filename, _MAX_FNAME);
	if (strcmp(filename + strlen(filename) - 4, ".txt"))strcat_s(filename, _MAX_FNAME,  ".txt");

	ofstream fout;			//создаем поток
	fout.open(filename, std::ios_base::app); //открываем поток //вторая часть - чтобы дописывать в файле
	fout << "Hello files" << endl;
	fout.close();
	//system("notepad File.txt");

	char sz_command[_MAX_FNAME] = "notepad ";
	strcat_s(sz_command, _MAX_FNAME, filename);
	system(sz_command);
#endif
#ifdef READ_FROM_FILE
	//читать из файла
	ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		const int SIZE = 1256; //для того, чтобы было куда сохранять введенный текст
		char sz_buffer[SIZE]{};
		while (!fin.eof())	  //пока не конец файла
		{
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error:File not found" << endl;
	}
#endif
}